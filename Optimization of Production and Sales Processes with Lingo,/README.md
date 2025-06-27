# Production Optimization Over a 5-Year Horizon

## Overview

This project presents a five-year optimization strategy for a manufacturing company with limited land and machinery resources. The goal is to maximize profit by managing production planning, material allocation, machine utilization, and labor constraints using mathematical modeling.

The project was developed as part of a university operations research and optimization course, using **LINGO** as the primary optimization solver.

## Problem Statement

The company owns a 200-hectare land with 120 manufacturing machines, split into two types:
- Type I: Requires 2.3 hectares per machine and produces Type I products.
- Type II: Requires 1 hectare per machine and produces Type II products.

Constraints include:
- Land usage conflicts (no overlap for machine installation, production, or material generation).
- Depreciation of machines and products over time.
- Space and cost limitations for machine expansion and material storage.
- Labor availability and cost scaling.
- External purchase/sale prices for materials.

The company must decide how to:
- Allocate machines and land each year.
- Manage raw material production or purchase.
- Schedule product transformations and sales.
- Optimize labor and operational costs.

## Objective

Maximize the total 5-year profit considering:
- Product revenue (immediate and delayed).
- Machinery cost and depreciation.
- Material production, purchase, and resale.
- Labor costs and constraints.

## Tools Used

- [LINGO](https://www.lindo.com/) for mathematical modeling and solving.
- Microsoft Excel for input/output visualization and sensitivity analysis.

## Outputs

- Model achieved a **global optimal solution** with an objective value of **984,670**.
- Conducted **sensitivity analysis** for key objective coefficients and right-hand side constraints.
- Output files include:
  - `.lng` optimization model
  - Excel file with solution and sensitivity ranges
  - Final report (in English)

## Files

- `model.lng` – LINGO source code for the model
- `report_en.pdf` – Final report with model description, variables, objective, constraints, and analysis
- `sensitivity_analysis.xlsx` – Sensitivity and optimization output visualizations
