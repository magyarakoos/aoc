open("input") do f
    m = match(r"/.{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)/gm", readline(f))
    
end