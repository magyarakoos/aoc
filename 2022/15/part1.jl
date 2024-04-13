rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"

for l in eachline(open("input", "r"))
    # println(l)
    for s in match(rx, l)
        println(s)
    end
    println()
end