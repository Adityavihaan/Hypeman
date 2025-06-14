#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include <chrono>
#include <cstdlib>
#include <map>

namespace fs = std::filesystem;

const std::string CONFIG_DIR = std::string(getenv("HOME")) + "/.config/hypeman";
const std::string CONFIG_FILE = CONFIG_DIR + "/config.toml";
const std::string QUOTE_FILE = CONFIG_DIR + "/quotes.txt";
const std::string ART_FILE = CONFIG_DIR + "/art.txt";

// ANSI color map
std::string get_color_code(const std::string& color) {
    if (color == "red") return "\033[31m";
    if (color == "green") return "\033[32m";
    if (color == "yellow") return "\033[33m";
    if (color == "blue") return "\033[34m";
    if (color == "magenta") return "\033[35m";
    if (color == "cyan") return "\033[36m";
    return "\033[0m"; // default
}

void create_default_files() {
    fs::create_directories(CONFIG_DIR);

    // config.toml
    if (!fs::exists(CONFIG_FILE)) {
        std::ofstream cfg(CONFIG_FILE);
        cfg << "color = \"cyan\"\n";
        cfg << "quote_style = \"boxed\"\n";
        cfg.close();
    }

    // quotes.txt
    if (!fs::exists(QUOTE_FILE)) {
        std::ofstream qf(QUOTE_FILE);
        std::vector<std::string> default_quotes = {
            "Stay hungry. Stay foolish. – Steve Jobs",
            "Talk is cheap. Show me the code. – Linus Torvalds",
            "Programs must be written for people to read. – Harold Abelson",
            "Experience is the name everyone gives to their mistakes. – Oscar Wilde",
            "Simplicity is the soul of efficiency. – Austin Freeman",
            "The only way to learn a new programming language is by writing programs in it. – Dennis Ritchie",
            "In theory, theory and practice are the same. In practice, they’re not. – Yogi Berra",
            "First, solve the problem. Then, write the code. – John Johnson",
            "If debugging is the process of removing bugs, then programming must be the process of putting them in. – Edsger Dijkstra",
            "Programs are meant to be read by humans and only incidentally for computers to execute. – Donald Knuth",
            // Add 90 more
        };
        for (int i = 1; i <= 100; ++i) {
            if (i <= default_quotes.size())
                qf << "\"" << default_quotes[i - 1] << "\"\n";
            else
                qf << "\"Motivational Quote #" << i << "\"\n";
        }
        qf.close();
    }

    // art.txt
    if (!fs::exists(ART_FILE)) {
        std::ofstream af(ART_FILE);
        for (int i = 1; i <= 10; ++i) {
            af << "art" << i << " {\n";
            af << "  ╔══════════════════════════════╗\n";
            af << "  ║         HYPEMAN " << i << "           ║\n";
            af << "  ╚══════════════════════════════╝\n";
            af << "}\n\n";
        }
        af.close();
    }
}

// Parse all quotes into vector
std::vector<std::string> load_quotes() {
    std::ifstream file(QUOTE_FILE);
    std::vector<std::string> quotes;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) quotes.push_back(line);
    }
    return quotes;
}

// Parse all ASCII arts into map
std::vector<std::vector<std::string>> load_arts() {
    std::ifstream file(ART_FILE);
    std::vector<std::vector<std::string>> arts;
    std::string line;
    bool in_art = false;
    std::vector<std::string> current_art;

    while (std::getline(file, line)) {
        if (line.find('{') != std::string::npos) {
            in_art = true;
            current_art.clear();
            continue;
        }
        if (line.find('}') != std::string::npos) {
            in_art = false;
            arts.push_back(current_art);
            continue;
        }
        if (in_art) current_art.push_back(line);
    }
    return arts;
}

std::string pick_random_quote(const std::vector<std::string>& list) {
    if (list.empty()) return "\"No quotes found.\"";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, list.size() - 1);
    return list[dist(gen)];
}

std::vector<std::string> pick_random_art(const std::vector<std::vector<std::string>>& list) {
    if (list.empty()) return { "╔═══════════╗", "║  no art   ║", "╚═══════════╝" };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, list.size() - 1);
    return list[dist(gen)];
}

std::string load_config_color() {
    std::ifstream file(CONFIG_FILE);
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("color") != std::string::npos) {
            size_t start = line.find("\"") + 1;
            size_t end = line.rfind("\"");
            return line.substr(start, end - start);
        }
    }
    return "cyan";
}

void print_boxed_quote(const std::string& quote, const std::string& color) {
    std::string border;
    for (size_t i = 0; i < quote.length() + 4; ++i) border += "─";

    std::cout << get_color_code(color) << "╭" << border << "╮\n";
    std::cout << "│  " << quote << "  │\n";
    std::cout << "╰" << border << "╯\n\033[0m";
}

int main() {
    create_default_files();

    std::string color = load_config_color();
    std::vector<std::string> quotes = load_quotes();
    std::vector<std::vector<std::string>> arts = load_arts();

    std::string quote = pick_random_quote(quotes);
    std::vector<std::string> art = pick_random_art(arts);

    std::cout << get_color_code(color);
    for (const auto& line : art) std::cout << line << '\n';
    std::cout << "\033[0m\n";

    print_boxed_quote(quote, color);

    return 0;
}

