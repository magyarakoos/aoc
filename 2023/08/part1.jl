f = open("input", "r")
(inst = readline(f); readline(f))
for l in eachline(f)
    a, b, c = [match(r"\w+", l)[i] for i in 1:3]
end