import itertools
import pandas as pd

valores = list(itertools.product([0,1],[0,1],[0,1]))  # (X,Y,Z)

filas = []
for (X, Y, Z) in valores:
    xy = X and Y
    xy_prime = int(not xy)     # (XY)'
    
    z_prime = int(not Z)       # Z'
    y_prime = int(not Y)       # Y'
    
    z_plus_y_prime = int(Z or y_prime)   # (Z + Y')
    x_plus_z_prime = int(X or (not Z))   # (X + Z')
    
    # Producto: Z'(Z + Y')(X + Z')
    prod = z_prime and z_plus_y_prime and x_plus_z_prime
    
    # Expresión final: (XY)' + [Z'(Z + Y')(X + Z')]
    expr_final = xy_prime or prod
    
    filas.append({
        'X': X,
        'Y': Y,
        'Z': Z,
        'XY': int(xy),
        '(XY)': int(xy),
        '(XY)\'': xy_prime,
        'Z\'': z_prime,
        'Y\'': y_prime,
        '(Z + Y\')': z_plus_y_prime,
        '(X + Z\')': x_plus_z_prime,
        'Z\'(Z+Y\')(X+Z\')': int(prod),
        'Expresión': int(expr_final)
    })

df = pd.DataFrame(filas)
# Orden lógico de las combinaciones (0,0,0) hasta (1,1,1)
df = df.sort_values(by=['X','Y','Z']).reset_index(drop=True)
df
