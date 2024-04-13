rx = r"/.{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)/gm"
open("input") do f
    m = [parse.(Int, match(, readline(f))[i]) for i in 1:4]
    println(m)
end