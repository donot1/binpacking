import matplotlib.pyplot as plt

bestFit = {
    "bimodal": [7.2, 6.87, 5.86, 5.9818],
    "binomial": [6, 5.56, 5.196, 5.0708],
    "uniform": [5.8, 5.16, 5.228, 5.142]
}

bestFitDecreasing = {
    "bimodal": [7.2, 6.89, 5.887, 5.9731],
    "binomial": [5.6, 5.28, 5.086, 5.0303],
    "uniform": [5.5, 5.37, 5.084, 5.0911]
}

firstFit = {
    "bimodal": [7.2, 6.87, 5.866, 5.9818],
    "binomial": [6, 5.67, 5.249, 5.0978],
    "uniform": [5.8, 5.43, 5.291, 5.1904]
}

firstFitDecreasing = {
    "bimodal": [7.2, 6.89, 5.887, 5.9731],
    "binomial": [5.6, 5.67, 5.086, 5.0303],
    "uniform": [5.5, 5.16, 5.084, 5.0911]
}


fig, ax = plt.subplots()
plt.title("Binomial Distribution")
plt.xlabel("Number of items")
plt.ylabel("Number of bins (scaled)")
plt.plot([10, 100, 1000, 10000], bestFit["binomial"], label="Best Fit")
plt.plot([10, 100, 1000, 10000], bestFitDecreasing["binomial"], label="Best Fit Decreasing")
plt.plot([10, 100, 1000, 10000], firstFit["binomial"], label="First Fit")
plt.plot([10, 100, 1000, 10000], firstFitDecreasing["binomial"], label="First Fit Decreasing")
plt.legend()
plt.show()


        
