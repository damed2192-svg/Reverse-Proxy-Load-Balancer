# 🚀 VPS Reverse Proxy + Load Balancer (C++)

A lightweight reverse proxy and load balancer written in C++.
This project demonstrates how core networking components like reverse proxy, request routing, and load balancing work at a low level.

---

## ✨ Features

* Reverse proxy by domain
* Load balancing strategies:

  * Round Robin
  * Random
  * Single backend
* Health check for backend servers
* Configurable via YAML/JSON
* High-performance using C++ networking

---

## 🧠 Architecture

```
Client → Proxy Server → Load Balancer → Backend Servers
```

---

## 📦 Project Structure

```
vps-reverse-proxy/
├── src/
│   ├── main.cpp              # Entry point
│   │
│   ├── proxy/
│   │   ├── Proxy.cpp
│   │   ├── Proxy.h
│   │
│   ├── load_balancer/
│   │   ├── LoadBalancer.cpp
│   │   ├── LoadBalancer.h
│   │
│   ├── health/
│   │   ├── HealthCheck.cpp
│   │   ├── HealthCheck.h
│   │
│   ├── config/
│   │   ├── Config.cpp
│   │   ├── Config.h
│   │
│   └── utils/
│       ├── Logger.cpp
│       ├── Logger.h
│
├── configs/
│   └── config.yaml
│
├── CMakeLists.txt
├── Dockerfile
└── README.md
```

---

## ⚙️ Configuration

Example:

```yaml
server:
  port: 8080

routes:
  - domain: "app.local"
    backends:
      - "http://localhost:5001"
      - "http://localhost:5002"
    strategy: "round-robin"
```

---

## ▶️ Build & Run

### 1. Clone repo

```bash
git clone https://github.com/yourusername/vps-reverse-proxy.git
cd vps-reverse-proxy
```

### 2. Build with CMake

```bash
mkdir build
cd build
cmake ..
make
```

### 3. Run

```bash
./proxy_server
```

---

## 🐳 Run with Docker

```bash
docker build -t vps-proxy .
docker run -p 8080:8080 vps-proxy
```

---

## 🔁 Load Balancing Strategies

| Strategy    | Description                |
| ----------- | -------------------------- |
| round-robin | Distribute requests evenly |
| random      | Random backend selection   |
| single      | Always use one backend     |

---

## 📊 Example Use Case

* Route traffic to multiple backend services
* Balance load across servers
* Simulate basic NGINX-like behavior

---

## 🔮 Future Improvements

* HTTPS support (OpenSSL)
* Epoll / async I/O optimization
* Web dashboard
* Rate limiting
* Metrics (Prometheus)

---

## 🧑‍💻 Tech Stack

* C++
* POSIX sockets / networking
* CMake
* Docker

---

## 📄 License

MIT License


