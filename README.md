# 🚀 VPS Reverse Proxy + Load Balancer

A lightweight reverse proxy and load balancer written in Go.
This project is designed to simulate core features of tools like NGINX and Traefik in a simple and educational way.

---

## ✨ Features

* Reverse proxy by domain
* Load balancing strategies:

  * Round Robin
  * Random
  * Single backend
* Health check (auto remove dead servers)
* Configurable via YAML
* Docker support

---

## 🧠 Architecture

```
Client → Proxy Server → Load Balancer → Backend Servers
```

---

## 📦 Project Structure

```
vps-reverse-proxy/
├── cmd/server            # Entry point
├── internal/
│   ├── proxy/            # Core proxy logic
│   ├── config/           # Config loader
│   ├── server/           # HTTP server
│   └── utils/            # Helpers
├── configs/              # YAML configs
├── scripts/              # Run scripts
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

## ▶️ Run Locally

### 1. Clone repo

```bash
git clone https://github.com/yourusername/vps-reverse-proxy.git
cd vps-reverse-proxy
```

### 2. Run

```bash
go run cmd/server/main.go
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

* Multiple backend services running on different ports
* Route traffic by domain
* Distribute load automatically

---

## 🔮 Future Improvements

* HTTPS support (Let's Encrypt)
* Web dashboard
* Rate limiting
* Authentication
* Metrics (Prometheus)

---

## 🧑‍💻 Tech Stack

* Go (Golang)
* Docker

---

## 📄 License

MIT License
