#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include <cstdlib>

namespace fs = std::filesystem;
using namespace std;

const string CONFIG_DIR  = string(getenv("HOME")) + "/.config/hypeman";
const string CONFIG_FILE = CONFIG_DIR + "/config.toml";
const string QUOTE_FILE  = CONFIG_DIR + "/quotes.txt";
const string ART_FILE    = CONFIG_DIR + "/art.txt";

string get_color_code(const string &color) {
    if (color == "red")     return "\033[31m";
    if (color == "green")   return "\033[32m";
    if (color == "yellow")  return "\033[33m";
    if (color == "blue")    return "\033[34m";
    if (color == "magenta") return "\033[35m";
    if (color == "cyan")    return "\033[36m";
    return "\033[0m";
}

void create_default_files() {
    fs::create_directories(CONFIG_DIR);

    if (!fs::exists(CONFIG_FILE)) {
        ofstream cfg(CONFIG_FILE);
        cfg << "color = \"cyan\"\n";
        cfg << "quote_style = \"boxed\"\n";
    }

    if (!fs::exists(QUOTE_FILE))
        ofstream(QUOTE_FILE);

    if (!fs::exists(ART_FILE))
        ofstream(ART_FILE);
}

vector<string> load_quotes() {
    ifstream file(QUOTE_FILE);
    vector<string> quotes;
    string line;
    while (getline(file, line))
        if (!line.empty()) quotes.push_back(line);
    return quotes;
}

vector<vector<string>> load_arts() {
    ifstream file(ART_FILE);
    vector<vector<string>> arts;
    string line;
    bool in_art = false;
    vector<string> current_art;

    while (getline(file, line)) {
        if (line.find('{') != string::npos) {
            in_art = true;
            current_art.clear();
            continue;
        }
        if (line.find('}') != string::npos) {
            in_art = false;
            arts.push_back(current_art);
            continue;
        }
        if (in_art) current_art.push_back(line);
    }
    return arts;
}

string pick_random_quote(const vector<string> &list) {
    if (list.empty()) return "\"No quotes found.\"";
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, list.size() - 1);
    return list[dist(gen)];
}

vector<string> pick_random_art(const vector<vector<string>> &list) {
    if (list.empty()) return {"╔═══════════╗", "║  no art   ║", "╚═══════════╝"};
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, list.size() - 1);
    return list[dist(gen)];
}

string load_config_color() {
    ifstream file(CONFIG_FILE);
    string line;
    while (getline(file, line)) {
        size_t pos = line.find("color");
        if (pos != string::npos) {
            size_t start = line.find('"', pos);
            size_t end   = line.rfind('"');
            if (start != string::npos && end != string::npos && end > start)
                return line.substr(start + 1, end - start - 1);
        }
    }
    return "cyan";
}

void print_boxed_quote(const string &quote, const string &color) {
    string border(quote.length() + 4, '─');
    cout << get_color_code(color) << "╭" << border << "╮\n";
    cout << "│  " << quote << "  │\n";
    cout << "╰" << border << "╯\n\033[0m";
}

int main() {
    create_default_files();

    string color = load_config_color();
    auto quotes  = load_quotes();
    auto arts    = load_arts();

    string quote = pick_random_quote(quotes);
    auto art     = pick_random_art(arts);

    cout << get_color_code(color);
    for (const auto &line : art) cout << line << '\n';
    cout << "\033[0m\n";

    print_boxed_quote(quote, color);
    return 0;
}
