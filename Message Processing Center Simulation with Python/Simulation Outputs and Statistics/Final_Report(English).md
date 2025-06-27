
# 📊 Final Report: Server Simulation & Policy Analysis

## 🧩 Project Title:
Simulation Modeling and Evaluation of Multi-Server Queuing Policies

## 🎯 Objective
This project aims to simulate and evaluate various server selection policies in a five-server queuing system. The analysis is focused on performance, fairness, and resource utilization across different policy types.

## 🛠 Simulation Overview

- **Arrival Distribution:** Exponential with mean 3.3 seconds.
- **Service Times:** Five servers with exponential service rates: 6s, 8s, 10s, 12s, 14s.
- **Policies Simulated:**
  - **Random Rule (RR):** Randomly selects among idle servers.
  - **Longest Idle Rule (LIR):** Chooses server with longest idle time since last job.
  - **Shortest Idle Rule (SIR):** Chooses server with shortest idle time since last job.
  - **Longest Total Idle Rule (LTIR):** Chooses server with longest total idle time since beginning.

## 🧪 Methodology

- Each simulation runs for 1000 seconds.
- Each policy was repeated for 700 iterations to generate stable averages.
- Performance metrics collected:
  - Number of messages processed by each server
  - Total idle time per server
  - Number of lost messages
  - Server utilization rate
  - Cold start time analysis

## 📈 Results Summary

- **Fairness Evaluation:**
  - LTIR policy achieved more equitable distribution of jobs among servers.
  - RR, LIR, and SIR showed favoritism toward faster servers, leading to uneven workload.

- **Performance Metrics:**
  - Faster servers handled significantly more messages in all policies.
  - LTIR reduced variance in total idle time and led to better fairness.
  - Message loss was minimized under LTIR due to optimized idle usage.

- **Cold Start Behavior:**
  - Systems stabilized after approximately 100–120 seconds.
  - All policies showed early message loss spikes, which decreased with warm-up.

## 🔍 Insights

- The policy choice significantly influences resource utilization.
- LTIR, though more complex, results in better fairness and smoother performance.
- Simulations like this can be extended to include queue buffering, cost models, or dynamic arrival rates.

## 🧠 Conclusion

This simulation provides practical insights into the trade-offs of server selection strategies in distributed systems. LTIR is a strong candidate for balanced and efficient resource management.

