# Salary Class Prediction using HR Data

This project was part of a university-level data mining course and focuses on building predictive models to classify employees into salary categories based on various HR-related features.

## 🧠 Objective
Develop an interpretable classification model that predicts the **salary class** of employees using HR data. The dataset includes features such as satisfaction level, work hours, and job role. The goal is to evaluate multiple machine learning models and identify the most accurate one.

## 📊 Project Workflow

1. **Data Preprocessing**
   - Removed duplicates and outliers
   - Handled imbalanced data using SMOTE
   - Performed PCA for dimensionality reduction

2. **Exploratory Data Analysis**
   - Visualized distributions and correlations among features
   - Assessed relationships between predictors and salary class

3. **Modeling Techniques Used**
   - K-Nearest Neighbors (KNN)
   - Decision Tree
   - Random Forest
   - Logistic Regression
   - Naive Bayes
   - LDA / QDA

4. **Model Evaluation**
   - Used accuracy, confusion matrices, and cross-validation
   - KNN and Random Forest showed the best performance (~74% accuracy)

5. **Interpretability**
   - Focused on models that offer explainability
   - Evaluated feature importance and the model’s ability to distinguish salary tiers

## 📁 Files

| `/Reports`         Reports and Analysis            
| `main.py`          Jupyter Notebook containing full analysis and modeling 
| `README.md`        Project overview (this file)                     

## 💡 Tools & Libraries
- Python
- scikit-learn
- pandas, numpy
- seaborn, matplotlib
- imblearn (for SMOTE)
- statsmodels

## 📌 Notes
- Dataset was provided as part of the academic course and cannot be shared publicly.
- Full analysis and insights are available in `report_en.pdf`.

