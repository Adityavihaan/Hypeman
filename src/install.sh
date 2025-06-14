#!/bin/bash

# Hypeman Installer

# Colors
CYAN='\033[1;36m'
GREEN='\033[1;32m'
BOLD='\033[1m'
RESET='\033[0m'

# Title
echo -e "${CYAN}${BOLD}"
echo "╔══════════════════════════════════════════╗"
echo "║        Installing Hypeman CLI Tool       ║"
echo "╚══════════════════════════════════════════╝"
echo -e "${RESET}"

# Check g++
if ! command -v g++ &> /dev/null; then
    echo -e "${RED}Error: g++ is not installed. Please install it and rerun.${RESET}"
    exit 1
fi

# Compile
echo -e "${CYAN}→ Compiling source code...${RESET}"
g++ main.cpp -o hypeman
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Compilation failed. Fix errors in main.cpp.${RESET}"
    exit 1
fi
echo -e "${GREEN}✓ Compilation successful.${RESET}"

# Install binary
echo -e "${CYAN}→ Moving hypeman to /usr/bin (requires sudo)...${RESET}"
sudo mv hypeman /usr/bin/hypeman
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Failed to move binary to /usr/bin/.${RESET}"
    exit 1
fi
echo -e "${GREEN}✓ Installed to /usr/bin/hypeman${RESET}"

# Setup config
echo -e "${CYAN}→ Creating config at ~/.config/hypeman/${RESET}"
mkdir -p ~/.config/hypeman

# Copy default config/art if present
cp -n quotes.txt ~/.config/hypeman/quotes.txt 2>/dev/null
cp -n art.txt ~/.config/hypeman/art.txt 2>/dev/null
cp -n config.toml ~/.config/hypeman/config.toml 2>/dev/null

echo -e "${GREEN}✓ Default config files set up.${RESET}"

# Finish
echo -e "${BOLD}${GREEN}"
echo "✔ Hypeman installed successfully!"
echo -e "${RESET}"
echo -e "${CYAN}🔥 Run it anytime using: ${BOLD}hypeman${RESET}"
echo -e "${CYAN}🎉 Stay hyped, stay awesome. Thanks for installing Hypeman.${RESET}"
