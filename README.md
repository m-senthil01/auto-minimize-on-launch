# Auto Minimize on Launch – Windhawk Mod

Automatically minimizes specific application windows right after launch.

---

## 💡 Features

- Automatically minimizes targeted windows when they open
- Lightweight and runs in the background
- Works with any executable (Notepad, Paint, etc.)
- Ideal for minimizing background utilities or launchers

---

## ⚙️ How It Works

This Windhawk mod hooks into the window creation process and minimizes windows matching your target executable names (e.g., `notepad.exe`) within 1 second after launch.

You can easily modify which apps are affected in the source code.

---

## 🧠 Example Use Case

- You want `Notepad` to open minimized instead of fullscreen
- You launch a program automatically at startup but don’t want it to appear on-screen

---

## 🛠️ Installation

1. Install [Windhawk](https://windhawk.net/)
2. [Download the latest `.whmod` file from Releases](https://github.com/m-senthil01/auto-minimize-on-launch/releases)
3. Double-click the `.whmod` file or open it via Windhawk → "Add mod"
4. Enable the mod from the Windhawk dashboard
5. Done!

---

## 📝 Configuration

Currently, target applications (like `notepad.exe`) are hard-coded in the mod’s source. You can edit the `.cpp` file and recompile the mod to customize which apps get minimized.

In future versions, a settings UI may be added for easier control.

---

## 📷 Screenshot

> 

---

## 🔒 License

This mod is released under the [MIT License](LICENSE).

---

## 🤝 Contributions

Feel free to fork the repo, submit issues, or open pull requests
