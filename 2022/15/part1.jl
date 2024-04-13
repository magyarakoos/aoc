rx = r"/.{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)/gm"
open("input") do f
    # m = [parse.(Int, [i]) for i in 1:4]
    println(readline(f))
    println(match(rx, readline(f)))
end
f = open("input")