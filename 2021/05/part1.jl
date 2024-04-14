m = zeros(Int, 1000, 1000)
map(l -> match(r"(\d+),(\d+) -> (\d+),(\d+)", l), readlines("input"))