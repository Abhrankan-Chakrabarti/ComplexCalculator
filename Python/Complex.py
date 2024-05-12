from math import atan, cos, e, pi, sin
class Complex:
	def __init__(self, a=0, b=0, pol=False, disp=False, sym='i'):
		if pol not in (False, True):
			b = b, self.angle(pol)
		elif pol:
			pol = b[1][0]
		self.a, self.b, self.u, self.disp, self.sym = a, b, pol, disp, sym
	def angle(self, u):
		u = u.lower().strip()[:1]
		if u == 'r':
			return ' rad', 1
		if u == 'g':
			return u, 200/pi
		return '°', 180/pi
	def mod(self):
		fm = (self.a**2+self.b**2)**0.5
		m = int(fm)
		if fm == m:
			fm = m
		return fm
	def arg(self, u):
		u = self.angle(u)
		if self.a>0:
			return Complex(b=(atan(self.b/self.a)*u[1], u))
		if self.a==0:
			if self.b>0:
				return Complex(b=(pi/2*u[1], u))
			elif self.b<0:
				return Complex(b=(-pi/2*u[1], u))
			return Complex(b=(0, u))
		if self.b>=0:
			return Complex(b=((atan(self.b/self.a)+pi)*u[1], u))
		return Complex(b=((atan(self.b/self.a)-pi)*u[1], u))
	def conjg(self):
		if self.u != False:
			return Complex(self.a, -self.b[0], self.b[1][0])
		return Complex(self.a, -self.b)
	def reci(self):
		return Complex(1, 0, self.u)/self
	def pol(self, u=''):
		return Complex(self.mod(), self.arg(u).b, pol=True)
	def rec(self):
		i = self.b[0]/self.b[1][1]
		return Complex(self.a*cos(i), self.a*sin(i))
	def __add__(self, z):
		if self.disp:
			if not l:
				l.append(0)
			l[0] += 1
			i, j = l[0], l[0] + 1
		u = False
		if self.u != False or z.u != False:
			u = self.u
			if self.u != False and z.u != False and self.b == (self.b[1][1]/z.b[1][1]*z.b[0], self.b[1]):
				return Complex(self.a+z.a, self.b, pol=True)
			if self.u != False:
				self = self.rec()
				if self.disp:
					print(' + '.join(f"z{k+1}" for k in range(i)), f"= {self}")
			if z.u != False:
				z = z.rec()
				if self.disp:
					print(f"z{j} = {z}")
		z = Complex(self.a+z.a, self.b+z.b)
		if u != False:
			if self.disp:
				print(' + '.join(f"z{k+1}" for k in range(j)), f"= {z}")
			if j == n:
				z = z.pol(u)
		return z
	def __sub__(self, z):
		if self.disp:
			if not l:
				l.append(0)
			l[0] += 1
			i, j = l[0], l[0] + 1
		u = False
		if self.u != False or z.u != False:
			u = self.u
			if self.u != False and z.u !=False and self.b == (self.b[1][1]/z.b[1][1]*z.b[0], self.b[1]):
				return Complex(self.a-z.a, self.b, pol=True)
			if self.u != False:
				self = self.rec()
				if self.disp:
					print(' - '.join(f"z{k+1}" for k in range(i)), f"= {self}")
			if z.u != False:
				z = z.rec()
				if self.disp:
					print(f"z{j} = {z}")
		z = Complex(self.a-z.a, self.b-z.b)
		if u != False:
			if self.disp:
				print(' - '.join(f"z{k+1}" for k in range(j)), f"= {z}")
			if j == n:
				z = z.pol(u)
		return z
	def __mul__(self, z):
		if self.disp:
			if not l:
				l.append(0)
			l[0] += 1
			j = l[0] + 1
		if self.u != False:
			if z.u == False:
				z = z.pol(self.u)
				if self.disp:
					print(f"z{j} = {z}")
			elif self.u != z.u:
				z.b = self.b[1][1]/z.b[1][1]*z.b[0], self.b[1]
				if self.disp:
					print(f"z{j} = {z}")
			return Complex(self.a*z.a, (self.b[0]+z.b[0], self.b[1]), pol=True)
		if z.u != False:
			z = z.rec()
			if self.disp:
				print(f"z{j} = {z}")
		return Complex(self.a*z.a-self.b*z.b, self.a*z.b+self.b*z.a)
	def __truediv__(self, z):
		if self.disp:
			if not l:
				l.append(0)
			l[0] += 1
			j = l[0] + 1
		if self.u != False:
			if z.u == False:
				z = z.pol(self.u)
				if self.disp:
					print(f"z{j} = {z}")
			elif self.u != z.u:
				z.b = self.b[1][1]/z.b[1][1]*z.b[0], self.b[1]
				if self.disp:
					print(f"z{j} = {z}")
			return Complex(self.a/z.a, (self.b[0]-z.b[0], self.b[1]), pol=True)
		if z.u != False:
			z = z.rec()
			if self.disp:
				print(f"z{j} = {z}")
		c = z.a**2+z.b**2
		return Complex((self.a*z.a+self.b*z.b)/c, (z.a*self.b-self.a*z.b)/c)
	def __pow__(self, z):
		if self.u == False:
			self = self.pol()
		if z.u != False:
			z = z.rec()
		return Complex(self.a/e**(self.b[0]/self.b[1][1]*z.b), (z.a*self.b[0], self.b[1]), pol=True)
	def __repr__(self):
		if type(self.b) == tuple:
			s, b, u = '', *self.b
			if self.u != False:
				a = self.a
				x, y = int(a), int(b)
				if x == a:
					a = x
				if y == b:
					b = y
				s = f"{a}∠"
			s += f"{b}{u[0]}"
			return s
		a, b, sym = self.a, self.b, self.sym
		x, y = int(a), int(b)
		if x == a:
			a = x
		if y == b:
			b = y
		if b >= 0:
			if b - 1:
				if b:
					return f"{a}+{b}{sym}"
				return f"{a}"
			return f"{a}+{sym}"
		if b + 1:
			return f"{a}-{-b}{sym}"
		return f"{a}-{sym}"
	def __str__(self):
		return repr(self)
if __name__ == '__main__':
	while 1:
		print('*'*16,' '.join('COMPLEX'),'',' '.join('NUMBER'),'*'*16)
		choices = 'Modulus Argument Conjugate Reciprocal Polar Rectangular Add Subtract Multiply Divide Power Exit'.split()
		for i, j in enumerate(choices):
			print(f"{i+1}. {j}")
		ch = input('Enter your choice :\t')
		if ch in '1 2 3 4 5 6'.split():
			if ch in ['3', '4']:
				pr = input('1. Polar\n2. Rectangular\nEnter your choice :\t')
			else:
				pr = '1' if ch == '6' else '2'
			if pr == '1':
				r = eval(input("Enter magnitude of z :\t").replace('^', '**') or 0)
			elif pr == '2':
				a = eval(input("Enter real part of z :\t").replace('^', '**') or 0)
				b = eval(input("Enter imaginary part of z :\t").replace('^', '**') or 0)
				z = Complex(a, b)
			else:
				print('Invalid choice.')
				continue
			if pr == '1' or ch in ['2', '5']:
				u = input("Enter its angle unit (d/r/g) :\t")
			if pr == '1':
				i = eval(input("Enter its inclination :\t").replace('^', '**') or 0)
				z = Complex(r, i, u)
			print(f"z = {z}")
			if ch == '1':
				z = '|z|', z.mod()
			elif ch == '2':
				z = 'arg(z)', z.arg(u)
			elif ch == '3':
				z = 'Conjg(z)', z.conjg()
			elif ch == '4':
				z = 'z⁻¹', z.reci()
			elif ch == '5':
				z = 'Pol(z)', z.pol(u)
			else:
				z = 'Rec(z)', z.rec()
			print(f"{z[0]} = {z[1]}")
		elif ch in '7 8 9 10 11'.split():
			z = []
			n = int(input(f"{choices[int(ch)-1]} how many? :\t"))
			yn = input('Display in between conversions? (y/n) :\t').lower().strip()[:1] == 'y'
			for j in range(1, n + 1):
				pr = input('1. Polar\n2. Rectangular\nEnter your choice :\t')
				if pr == '1':
					r = eval(input(f"Enter magnitude of z{j} :\t").replace('^', '**') or 0)
					u = input("Enter its angle unit (d/r/g) :\t")
					i = eval(input("Enter its inclination :\t").replace('^', '**') or 0)
					z.append(Complex(r, i, u, disp=yn))
				else:
					a = eval(input(f"Enter real part of z{j} :\t").replace('^', '**') or 0)
					b = eval(input(f"Enter imaginary part of z{j} :\t").replace('^', '**') or 0)
					z.append(Complex(a, b, disp=yn))
			for i, j in enumerate([i for i in z]):
				print(f"z{i+1} = {j}")
			op = dict(zip('7 8 9 10 11'.split(), '+ - * / **'.split()))[ch]
			l = []
			z = f" {op} ".join(f"z{i+1}" for i in range(n)), eval(op.join(f"z[{i}]" for i in range(n)))
			print(f"{z[0]} = {z[1]}")
		elif ch == '12':
			break
		else:
			print('Invalid choice.')
