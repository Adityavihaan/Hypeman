#!/bin/bash

# Hypeman Config Reinstaller

# ─── Colors ────────────────────────────────
CYAN='\033[1;36m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
RESET='\033[0m'

# ─── Header ────────────────────────────────
echo -e "${CYAN}${BOLD}"
echo "╔════════════════════════════════════════════╗"
echo "║     Hypeman - Reinstall Default Configs    ║"
echo "╚════════════════════════════════════════════╝"
echo -e "${RESET}"

# ─── Paths ────────────────────────────────
CONFIG_DIR="$HOME/.config/hypeman"
FILES=("art.txt" "quotes.txt" "config.toml")

# ─── Step 1: Remove old configs ───────────
echo -e "${YELLOW}🧹 Cleaning up old config files...${RESET}"
for file in "${FILES[@]}"; do
    if [ -f "$CONFIG_DIR/$file" ]; then
        rm "$CONFIG_DIR/$file"
        echo -e "${GREEN}✔ Removed $file"
    else
        echo -e "${CYAN}ℹ $file not found, skipping"
    fi
done

# ─── Step 2: Copy new configs ─────────────
echo -e "${YELLOW}\n📦 Installing fresh configs...${RESET}"
mkdir -p "$CONFIG_DIR"
for file in "${FILES[@]}"; do
    if [ -f "$file" ]; then
        cp "$file" "$CONFIG_DIR/"
        echo -e "${GREEN}✔ Installed $file"
    else
        echo -e "${CYAN}⚠ $file missing in current dir, skipped"
    fi
done

# ─── Done ─────────────────────────────────
echo -e "\n${GREEN}${BOLD}✅ Hypeman configs reinstalled successfully!${RESET}"
echo -e "${CYAN}📂 Path: ${BOLD}~/.config/hypeman/${RESET}"
echo -e "${CYAN}🎉 You're all set to run: ${BOLD}hypeman${RESET}"
