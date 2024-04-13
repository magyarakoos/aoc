f = open("input", "r")
(a = [], b = [])
for l in eachline(f)
    rx = r"Card \d+: ((?:\d+\s+)+)\| ((?:\d+\s+)+)"
    push!(a, rx.captures[1])
    push!(b, rx.captures[2])
end
