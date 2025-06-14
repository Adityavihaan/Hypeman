# 🎤 Hypeman

**Hypeman** is your personal terminal motivator. Every time you launch a terminal, Hypeman greets you with a random inspirational quote and a stylized ASCII or digital art banner to hype you up — just like a motivational coach in your CLI.

> 💬 _"Start your terminal session with purpose, with power, with HYPE!"_

---

## ✨ Features

- ✅ Displays a **random inspirational quote** on every run
- ✅ Accompanied by **random ASCII/digital art**
- ✅ Fully customizable: **add your own quotes, fonts, colors**
- ✅ No dependencies beyond standard C++
- ✅ Tiny, fast, offline — built for CLI lovers
- ✅ Plug into any shell (`bash`, `zsh`, `fish`) easily
- ✅ MIT Licensed & open source

---

## 🛠️ Why I Built This

I wanted something **fun, inspiring, and personal** to greet me every time I opened a terminal. Not just a logo — but real **motivation**, from quotes that matter, in a terminal-native way.  
Hypeman is for devs, hackers, writers, or anyone who lives in their terminal and wants a little daily boost.

---

## 📦 Installation

```bash
git clone https://github.com/Adityavihaan/Hypeman.git
cd hypeman
./install.sh          # Compiles and installs hypeman to /usr/bin/
./install-configs.sh  # Installs default quotes, config, and ASCII art
```

🚀 Usage

Simply run:
```bash
hypeman
```

Or add it to your shell startup file for automatic hype on every terminal launch.

🎨 Customization
🖼️ Add your own ASCII/Digital Art
Open ~/.config/hypeman/art.txt. Add more entries using this format:

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
You can put as many art and quotes you want.

Use artX { ... } for each new art block

Indent inside the {}

artX here X should only be a number.


🧾 Change Fonts, Sizes, Colors

Edit ~/.config/hypeman/config.toml. Options:
```bash
[style]
font = "default"        # Options: default, bold, small, block
color = "cyan"          # red, green, yellow, blue, magenta, cyan, white
quote_font_size = 1     # (future support, currently symbolic)

[settings]
randomize = true
```


🤔 Why Use Hypeman?

    Helps you start every terminal session with a positive mindset

    Boosts productivity through small motivational nudges

    Easy to extend with your favorite quotes or designs

    Adds personality to your command-line environment

    Works offline, runs instantly

📄 License

MIT License — do whatever you want, just give credit.

🙌 Contribute

Feel free to fork and PR!
Ideas welcome: random quote APIs, TUI modes, color themes, emoji banners — let's hype the world together 🎉

Made with ❤️ by Aditya to make terminals less boring and more 🔥

🧠 Why I Built Hypeman

I wanted to make the terminal more motivating — not just a cold shell, but something that could inspire.
 Hypeman turns your terminal into a place where every session starts with positivity,
 drive, and a reminder of why you do what you do.

🧾 Configuration

Your config is stored in:

```bash
~/.config/hypeman/
├── config.toml       # Font, color, style settings
├── quotes.txt        # One quote per line
└── art.txt           # Multiple ASCII/digital arts
```

💡 What Can You Use This For?

    Boosting your mood before coding 💪

    Reminding yourself of long-term goals 🎯

    Injecting creativity and fun into CLI workflows 🎨

    Getting inspired to push through burnout 🔥

    Or just to feel a little more human in a machine 🧠

🔧 Uninstall
```bash
sudo rm /usr/bin/hypeman
rm -rf ~/.config/hypeman
```
