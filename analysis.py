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

plt.cla()

fig, ax = plt.subplots()
plt.title("Bimodal Distribution")
plt.xlabel("Number of items")
plt.ylabel("Number of bins (scaled)")
plt.plot([10, 100, 1000, 10000], bestFit["bimodal"], label="Best Fit")
plt.plot([10, 100, 1000, 10000], bestFitDecreasing["bimodal"], label="Best Fit Decreasing")
plt.plot([10, 100, 1000, 10000], firstFit["bimodal"], label="First Fit")
plt.plot([10, 100, 1000, 10000], firstFitDecreasing["bimodal"], label="First Fit Decreasing")
plt.legend()
plt.show()

plt.cla()

fig, ax = plt.subplots()
plt.title("Uniform Distribution")
plt.xlabel("Number of items")
plt.ylabel("Number of bins (scaled)")
plt.plot([10, 100, 1000, 10000], bestFit["uniform"], label="Best Fit")
plt.plot([10, 100, 1000, 10000], bestFitDecreasing["uniform"], label="Best Fit Decreasing")
plt.plot([10, 100, 1000, 10000], firstFit["uniform"], label="First Fit")
plt.plot([10, 100, 1000, 10000], firstFitDecreasing["uniform"], label="First Fit Decreasing")
plt.legend()
plt.show()

plt.cla()


# bimodal, e.g.        
bestFitTime = [0.007997, 0.0638753, 0.675893, 8.32111]
bestFitDecreasingTime = [0.0065137, 0.0674007, 0.829683, 10.7817]
firstFitTime = [0.0026384, 0.0203386, 1.2065, 122.355]
firstFitDecreasingTime = [0.003397, 0.0300988, 1.50518, 135.479]

fig, ax = plt.subplots()
plt.title("Algorithm Running Times (Using Bimodal Distribution as example)")
plt.xlabel("Number of items")
plt.ylabel("Time (ms)")
plt.plot([10, 100, 1000, 10000], bestFitTime, label="Best Fit")
plt.plot([10, 100, 1000, 10000], bestFitDecreasingTime, label="Best Fit Decreasing")
plt.plot([10, 100, 1000, 10000], firstFitTime, label="First Fit")
plt.plot([10, 100, 1000, 10000], firstFitDecreasingTime, label="First Fit Decreasing")
plt.legend()
plt.show()