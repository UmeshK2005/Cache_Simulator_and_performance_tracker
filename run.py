import matplotlib.pyplot as plt

def plot_graph_from_files(filenames, labels):
    # Initialize lists to store all x and y values
    all_x_values = []
    all_y_values = []

    # Read data from each file and extract x, y values
    for filename in filenames:
        x_values = []
        y_values = []
        with open(filename, 'r') as file:
            for line in file:
                columns = line.strip().split()
                if len(columns) >= 2:
                    x_values.append(float(columns[0]))  # Assuming x values are in the second column
                    y_values.append(float(columns[1]))  # Assuming y values are in the first column
        all_x_values.append(x_values)
        all_y_values.append(y_values)

    # Plot the graph for each dataset
    for x_values, y_values in zip(all_x_values, all_y_values):
        plt.plot(x_values, y_values, marker='o', linestyle='-')

    # Customize plot attributes
    plt.xlabel('size of matrix(n)')
    plt.ylabel('time taken ')
    plt.title('time taken vs size')
    plt.grid(True)

    plt.legend(labels)  # Add legend for each file
    plt.savefig('time vs size.png')
labels = ["ijk","ikj","jik","kij","jki","kji"]  # List of labels
filenames = ["ijk.txt","ikj.txt","jik.txt","kij.txt","jki.txt","kji.txt"]  # List of filenames
plot_graph_from_files(filenames, labels)