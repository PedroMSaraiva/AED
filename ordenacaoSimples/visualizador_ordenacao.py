import pandas as pd
import matplotlib.pyplot as plt
from scipy.interpolate import UnivariateSpline


df = pd.read_csv(f'ex1/Dados_ordenacao.csv', names=['Input Size', 'Bubble Time', 'Insertion Time', 'Selection Time'])

# Acessando as colunas
input_sizes = df['Input Size'].tolist()
bubble_times = df['Bubble Time'].tolist()
insertion_times = df['Insertion Time'].tolist()
selection_times = df['Selection Time'].tolist()


# Mostra o grafico
plt.style.use('seaborn-v0_8-darkgrid')
plt.figure(figsize=(14, 7))

plt.scatter(input_sizes, bubble_times, s=10, color='teal', alpha=0.5, label='Bubble Sort')
plt.scatter(input_sizes, insertion_times, s=10, color='hotpink', alpha=0.5, label='Insertion Sort')
plt.scatter(input_sizes, selection_times, s=10, color='tomato', alpha=0.5, label='Selection Sort')

plt.xlabel("Tamanho do Input",fontsize=14)
plt.ylabel("Tempo de Execução (s)",fontsize=14)
plt.title("Analise de Tempo de Execução", fontsize=16)
plt.grid(True, which="both", linestyle="--", linewidth=0.5, color='gray')
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(loc='upper left')
plt.tight_layout()
plt.show()