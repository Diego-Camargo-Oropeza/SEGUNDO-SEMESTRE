A = set(['w', 'e', 'j', 'c', 'p', 'r'])
print(A)
type(A)

B = {'x', 'p', 'm', 'j', 'w', 'm'}
print(B)
type(B)

print("Set A cardinality: ", len(A))

print("Set B cardinality: ", len(B))

print('a' in A)

print('p' in B)

#Operaciones entre sets

union = A | B
print("Union de A y B:", union)

interseccion = A & B
print("Interseccion de A y B:", interseccion)

diferencia = A - B
print("Diferencia de A y B:", diferencia)

diferencia_simetrica = A ^ B
print("Diferencia simetrica de A y B:", diferencia_simetrica)

#Metodo de sets

#Add para agregar un elemento al set

C = {'h', 's', 'q'}
print("Set C:", C)
C.add('b')
print("Set C:", C)

#Remove para eliminar un elemento del set

C.remove('s')
print("Set C:", C)

#Exception handling para evitar errores si el elemento no existe en el set para que no tuene el programa jeje

try:
    C.remove('z')
except KeyError:
    print("El elemento no existe en el set")
    
#Discard para eliminar un elemento del set sin generar error si el elemento no existe

C.discard('a')
print("Set C:", C)

#Pop para eliminar un elemento aleatorio del set

C.pop()
print("Set C:", C)

#Clear para eliminar todos los elementos del set

C.clear()
print("Set C:", C)

### Practical example of set usuage no.1, prevent duplicates in a list of emails ###

#Lista de correos electrónicos con duplicados

correos=["juan@gmail.com","ana@yahoo.com","juan@gmail.com","luis@hotmail.com","ana@yahoo.com","maria@gmail.com"]

#Set para eliminar duplicados

correos_unicos = set(correos)

#Se convierte el set a lista

correos_unicos_list = list(correos_unicos)

print(correos_unicos_list)

### Practical example of set usuage no.2,  ###

#Lista de estudiantes que asistieron a un evento A y a un evento B

evento_A = ["Juan","Ana","Luis","Carlos","Maria"]
evento_B = ["Ana","Luis","Pedro","Maria","Carlos"]

#Convertir las listas en sets
set_A = set(evento_A)
set_B = set(evento_B)

#Consulta a) Quienes asistieron a ambos eventos (interseccion)
ambos_eventos = set_A & set_B

#Consulta b) estudiantes que asistieron a solo un evento (diferencia simetrica)
solo_un_evento = set_A ^ set_B

#Consulta c) estudiantes que asistieron al evento A pero no al evento B (diferencia)
solo_A = set_A - set_B

#Print results

print("Estudiantes que asistieron a ambos eventos:", ambos_eventos)
print("Estudiantes que asistieron a solo un evento:", solo_un_evento)
print("Estudiantes que asistieron al evento A pero no al evento B:", solo_A)