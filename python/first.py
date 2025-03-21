my_list = [10, 5, 15]

my_list.append(20) 
my_list.append(8) 

print("Items inside the list:", my_list)  

print("Number of elements:", len(my_list))  

my_list.sort()  

print("Sorted list:", my_list) 

my_list.remove(8)  

print("List after removing '8':", my_list)

### 3 extra methods: 

#Reverse to r e v e r s e the list
my_list.reverse()
print("Reversed list:", my_list)

#Extend to add multiple elements (outsider elements) to the list
my_list.extend([10, 5, 15, 20, 8])
print("Extended list:", my_list)

#Clear to remove all elements from the list
my_list.clear()
print("List after clearing:", my_list)





