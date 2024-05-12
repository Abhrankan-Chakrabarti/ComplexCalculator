from Complex import Complex

# Create a complex number
z = Complex(3, 4, disp=True)

# Calculate modulus
mod = z.mod()
print(f"Modulus: {mod}")

# Calculate argument in degrees
arg_deg = z.arg('d')
print(f"Argument (degrees): {arg_deg}")

# Calculate conjugate
conj = z.conjg()
print(f"Conjugate: {conj}")

# Calculate reciprocal
reci = z.reci()
print(f"Reciprocal: {reci}")

# Convert to polar form
pol = z.pol()
print(f"Polar form: {pol}")

# Convert to rectangular form
rec = z.rec()
print(f"Rectangular form: {rec}")