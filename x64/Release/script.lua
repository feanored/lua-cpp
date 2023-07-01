local lib = require("funcoesLib")

print(square(7))
print()

print(soma_sub(5, 3))
print()

for i=-2,5,1 do
	print(string.format("Fib(%2d) = %3d", i, fibonacci(i)))
end
