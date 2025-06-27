# Multi-Server Simulation & Policy Evaluation

This project simulates a multi-server queuing system to analyze the fairness and performance of different server selection policies. It was developed as part of an academic assignment during my undergraduate studies.

## 📌 Objective

To simulate a 5-server system processing messages with varying service times and evaluate how different dispatching policies affect:

- Server utilization
- Fairness of server selection
- Message loss rates
- Average idle time

## 🧩 Problem Description

- Incoming messages arrive with an **exponential interarrival time** (mean = 3.3 seconds).
- Each of the 5 servers has a unique **exponential service time** (mean = 6s, 8s, 10s, 12s, 14s respectively).
- If all servers are busy, a message is considered **lost**.
- If multiple servers are available, a **policy** is used to determine which server handles the message.

## 🛠️ Policies Simulated

1. **Random Rule (RR)** – Randomly chooses one of the idle servers.
2. **Idle Longest (LIR)** – Chooses the server with the longest idle time *since last job*.
3. **Idle Shortest (SIR)** – Chooses the server with the shortest idle time *since last job*.
4. **Total Idle Longest (LTIR)** – Chooses the server with the longest *total idle time* since the beginning of the simulation.

## 📊 Simulation Setup

- Simulation runs for **1000 seconds**, repeated **700 times** for each policy.
- Key metrics collected for each run:
  - Total messages processed per server
  - Total idle time per server
  - Lost messages
  - Server utilization percentage
  - Cold start period (where the system stabilizes)

## 📈 Results

The simulation outputs include:
- Excel logs (`Trace` and `Statistic` sheets)
- Cold start determination
- Statistical averages and standard deviations across all runs
- Comparative plots and discussions on fairness and performance

## 📁 Files

- `main.py` – Main simulation code
- `/Simulation Outputs and Statistics` – Folder containing generated Excel files,reports and visualizations
- `README.md` – This file

## 🔍 Key Insights

- **LTIR** policy shows more balanced utilization across servers.
- Faster servers naturally take on more load in **RR, LIR, and SIR**.
- Policy choice significantly impacts fairness and resource distribution.

## 🧠 Skills Demonstrated

- Discrete event simulation
- Statistical analysis and visualization
- Python scripting and modular code design
- Fairness evaluation in resource allocation

## 🗂️ Project Status

Completed as a university simulation assignment. A detailed analysis and discussion of the results is included in the final report (currently available only in Persian).
