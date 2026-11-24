<div align="center">

#NawaOS

**A lightweight, custom Linux-based operating system built from scratch using the Linux Kernel, BusyBox, and native C utilities.**

![Build Status](https://shields.io)
![Kernel](https://shields.io)
![Language](https://shields.io)
![License](https://shields.io)

</div>

---

##Overview

**NawaOS** is a minimal operating system that boots directly in RAM within seconds into a clean, interactive command-line environment. It demonstrates how the Linux kernel interacts with user-space utilities, virtual filesystems (`/proc`, `/sys`, `/dev`), and custom statically compiled C binaries.

### Key Features
- **Ultra-Fast RAM Boot:** Runs completely in memory (`initramfs`) with zero disk overhead.
-**Native Built-in C Commands:** Includes custom utilities compiled statically into `/bin` (`sysinfo`, `calc`).
-**Automated Cloud CI/CD:** Automatically compiles the Linux kernel, BusyBox, and all C commands on **GitHub Actions** (`ubuntu-24.04`) upon every push.
-**Plug-and-Play Command Architecture:** Drop any `.c` source file inside the `commands/` directory, and the build pipeline automatically compiles and integrates it as an OS command.

---

## Project Architecture

```text
NawaOS/
├── .github/
│   └── workflows/
│       └── build-os.yml   # Automated cloud build pipeline (Kernel + BusyBox + C apps)
├── commands/
│   ├── sysinfo.c          # Native command to display kernel & RAM statistics
│   └── calc.c             # Native command-line & interactive calculator
├── init                   # PID 1 initialization script & welcome banner
└── README.md              # Project documentation
```

---

##  Built-in Custom Commands

| Command | Usage Example | Description |
| :--- | :--- | :--- |
| **`sysinfo`** | `sysinfo` | Displays kernel version, CPU architecture, system uptime, and RAM usage. |
| **`calc`** | `calc 25 * 4` or `calc` | Built-in calculator supporting `+`, `-`, `*`, `/` in both CLI and interactive modes. |
| **`poweroff -f`** | `poweroff -f` | Safely halts and shuts down the operating system. |

### How to Add a New Command
1. Create a new C file in the `commands/` directory (e.g., `commands/hello.c`).
2. Push your changes to the `main` branch.
3. GitHub Actions will automatically compile it with `gcc -static` and place the executable inside `/bin/`.

---

## Quick Start (Download & Run)

### 1. Download the Pre-built OS
1. Navigate to the [**Actions**](https://github.com) tab in this repository.
2. Click on the latest successful workflow run (**Build NawaOS**).
3. Scroll down to the **Artifacts** section and download **`NawaOS-x86_64`**.
4. Extract the `.zip` archive to obtain `bzImage` (the kernel) and `initramfs.cpio.gz` (the root filesystem).

### 2. Boot with QEMU
Run **NawaOS** on Linux, Windows (WSL), or Android (Termux) using QEMU:

```bash
qemu-system-x86_64 -kernel bzImage -initrd initramfs.cpio.gz -nographic -append "console=ttyS0"
```

---

## License

This project combines the **Linux Kernel** (`GPLv2`) and **BusyBox** (`GPLv2`). All custom scripts and C utilities in this repository are distributed under the **GNU General Public License v2.0**.
