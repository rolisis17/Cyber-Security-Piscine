# Cyber Security Piscine

Small cybersecurity learning exercises focused on HTTP requests, response inspection, and experimenting with low-level tooling in Python and C++.

This repository is intentionally lightweight: it is a practice area for understanding how programs talk to remote services and how response data can be collected and inspected.

## Contents

```text
request.py    Python request experiment
spider.cpp    C++ / libcurl response-fetching experiment
```

## What it explores

- Sending HTTP requests
- Reading response bodies
- Handling request errors
- Using Python for quick scripting
- Using C++ with `libcurl` for lower-level request handling
- Thinking about tool behavior from a security-learning perspective

## Build and run

Python request sketch:

`request.py` is kept as an early `requests`-based exercise sketch. Inspect and adapt it before using it as a runnable tool.

C++ experiment with libcurl:

```bash
c++ -Wall -Wextra -Werror spider.cpp -lcurl -o spider
./spider
```

## Technical highlights

- Compares a quick Python approach with a C++ approach
- Uses `libcurl` callbacks to collect response data
- Keeps exercises small enough to inspect line by line
- Reinforces responsible experimentation with network-facing code

## Skills demonstrated

- Basic HTTP automation
- C++ and Python tool-building
- Response parsing mindset
- Debugging early-stage security exercises
- Understanding how request tools are built under the hood

## Responsible use

Run these exercises only against systems you own or have explicit permission to test. This repository is for learning, not for scanning or stressing third-party services.
