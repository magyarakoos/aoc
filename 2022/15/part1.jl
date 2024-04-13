rx = r"/.{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)/gm"

for l in eachline(open("input", "r"))
    println(l)
    println(match(rx, l))
end