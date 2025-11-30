<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/libftm.png" height="150" alt="42 libft Badge"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-blue" height="32"/>
  <img src="https://img.shields.io/github/languages/code-size/Ego8316/libft?color=5BCFFF" height="32"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Linux-0a97f5?style=for-the-badge&logo=linux&logoColor=white" height="32"/>
  <img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" height="32"/>
  <img src="https://img.shields.io/badge/WSL-0a97f5?style=for-the-badge&logo=linux&logoColor=white" height="32"/>
</p>

# libft

### 🎓 42 School – Final Grade: **125/100**

A custom C standard-library subset plus a few convenience helpers (string/memory routines, character checks, allocation helpers, singly linked lists, and `get_next_line`).

---

## 📦 Features
- Drop-in replacements for common libc calls (`memset`, `memcpy`, `strlcpy`, `atoi`, etc.).
- String utilities: trim, split, join, substring, iterative/functional mappers.
- Character classification/conversion helpers (`ft_is*`, `ft_tolower`, `ft_toupper`, `ft_isspace`, `ft_char_in_str`, `ft_stristype`).
- Memory and allocation helpers (`ft_calloc`, `ft_bzero`).
- Singly linked list API (creation, iteration, map, clear).
- File utilities: `get_next_line` plus `ft_put*` file-descriptor writers.

---

## 🛠️ Building
```bash
git clone https://github.com/Ego8316/libft.git
cd libft
make        # builds libft.a (mandatory)
make bonus  # builds bonus list functions if needed
```

---

## 🚀 Usage
```c
#include "libft.h"

int main(void)
{
    char  *hello = ft_strdup("hello");

    ft_striteri(hello, ft_toupper);
    ft_putstr_fd(hello, 1);
    free(hello);
    return (0);
}
```
Link your project with the generated `libft.a`, e.g. `cc your_code.c -L. -lft`.

---

## ✅ Testing
- Run your preferred tests after building: `make` (and `make bonus` if using list APIs).
- Norm compliance: `norminette` on the repository root.
- For `get_next_line`, test multiple FDs and varying `BUFFER_SIZE`.

---

## 📄 License
MIT License — see `LICENSE` for details.
