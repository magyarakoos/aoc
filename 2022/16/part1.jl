# f = map(
#     map(a -> (a[1], parse.(a[2]), split(a[3:end], ", ")), 
#         l -> match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)",l)), 
#     open("input", "r")
# )

# f = map(l -> match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
#     readlines("input"))

f = readlines("input")
for l in f
    for s in match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l)
        println(s)
    end
    println()
end