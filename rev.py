def rev(x):
	if x > 0:
 		sign = 1
	else:
		sign = -1
            
	x = abs(x)
	a = str(x)
	#print(a)
	#print(type(a))
	l = []
	for i in a:
		i = int(i)
		l.append(i)
	#print(len(l))
	s = 0
	for i in range(len(l)):
		s += l[i] * 10**(i)
		print(l[i], i, s)
	
            

            
	return s * sign


a = -12345
b = rev(a)
print(b)