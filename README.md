# Hypeman

**Hypeman** is a minimal terminal tool that shows a random motivational quote and ASCII/digital art every time you open your terminal. It's built for people who live in the CLI and want a little personal boost when they start working.

---

## Features

- Random motivational quote each time you run it
- Random ASCII or digital art banner
- Add your own quotes or art easily
- No external dependencies (pure C++)
- Fast, small, offline, terminal-native
- Works with any shell: `bash`, `zsh`, `fish`
- Open-source under MIT License

---

## Why Hypeman Exists

I wanted something that wasn't just a startup logo — but something that actually gave me a bit of motivation when I sat down to code. Quotes from people I admire. Art that feels unique. A CLI-native pep talk.

---

## Installation

```bash
git clone https://github.com/Adityavihaan/Hypeman.git
cd Hypeman
./install.sh          # Builds and installs Hypeman to /usr/bin
./install-configs.sh  # Adds default quotes, config, and art files
```

---

## Usage

```bash
hypeman
```

To run Hypeman every time you launch a terminal, add this to your shell startup file:

### For Bash
```bash
echo "hypeman" >> ~/.bashrc
```

### For Zsh
```bash
echo "hypeman" >> ~/.zshrc
```

---

## Customization

### Add Your Own Art

Edit:

```bash
~/.config/hypeman/art.txt
```

Example format:

```bash
art1 {
  ░█░░░▀█▀░█▀█░█▀▄
  ░█░░░░█░░█░█░█░█
  ░▀▀▀░▀▀▀░▀░▀░▀▀░
}
art2 {
  ／人◕ ‿‿ ◕人＼
  └──────────────┘
}
```

- Use `artX { ... }` format
- Each block should be indented
- `X` should be a number (`art1`, `art2`, `art3`, etc.)

---

### Add or Edit Quotes

Edit:

```bash
~/.config/hypeman/quotes.txt
```

- One quote per line

---

### Config Options

Edit:

```bash
~/.config/hypeman/config.toml
```

Available options:

```toml
[style]
font = "default"        # Options: default, bold, small, block
color = "cyan"          # Options: red, green, yellow, blue, magenta, cyan, white
quote_font_size = 1     # Not used yet

[settings]
randomize = true
```

---

## Why Use It?

- Makes your terminal feel personal
- Gives a mental boost when you start work
- A tiny ritual to improve mood and focus
- Offline and lightning fast
- Easy to extend with your own personality

---

## Config Files

All user data is stored in:

```bash
~/.config/hypeman/
├── config.toml       # Style settings
├── quotes.txt        # List of motivational quotes
└── art.txt           # Art blocks
```

---

## Uninstall

```bash
sudo rm /usr/bin/hypeman
rm -rf ~/.config/hypeman
```

---

## Contributing

Feel free to fork and open a PR. Ideas are welcome:

- Random quote APIs
- Color schemes
- TUI version
- Minimal mode / silent fallback
- JSON support

---

## License

MIT — free to use, modify, share. Credit appreciated.

---

## Made By

Aditya, for people who use their terminal like a second home.
