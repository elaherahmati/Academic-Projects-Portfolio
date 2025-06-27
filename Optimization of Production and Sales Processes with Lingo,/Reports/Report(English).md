📝 Production Optimization Over a 5-Year Horizon
📌 Project Overview
This project focuses on designing a 5-year production and resource management strategy for a manufacturing company that operates within limited spatial, labor, and machine availability constraints. The objective is to maximize the company’s profit by efficiently allocating land, machines, raw materials, and labor while respecting space conflicts, product depreciation, and resource limitations.

🧠 Decision Variables
X_ijkt: Quantity of product i produced in factory j using process k on day t in March.

W_ijkt: Quantity of product i produced in factory j using process k on day t in February.

Y_ijkt: Quantity of product i shipped from factory j in month t.

Z_ijkt: Quantity of product i sold locally by factory j in month t.

V_ijkt: Quantity of product i stored by factory j in month t.

🎯 Objective Function
The model aims to maximize total profit, considering:

Revenue from selling Type I and Type II products (both shipped and sold locally).

Costs of production, storage, and labor.

Depreciation of products and machines over time.

✅ Constraints
Balance of production, storage, shipping, and selling across all products and factories.

Land allocation limits per factory for each machine and material type.

Upper bounds on labor hours and land usage.

Sales and inventory limits to prevent overcapacity.

Machine and material degradation over time.

💡 Key Results
Global optimal solution found with an objective value of 984,670.

No infeasibilities encountered.

Sensitivity analysis showed that increasing certain selling prices or demand constraints leads to higher profits.

📊 Sensitivity Analysis
Analyzed:

Changes in objective coefficients (e.g., selling price of Type II product in March).

Changes in demand limits (e.g., maximum allowed inventory).

Identified stability regions for key constraints and their impact on profitability.

📁 Deliverables
LINGO code (.lng file)

Excel output file with:

Solver output

Sensitivity ranges and analysis

Visualizations of optimal regions

