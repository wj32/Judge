let a = stdin.ReadLine().Split() |> Array.map int
let b = stdin.ReadLine().Split() |> Array.map int
let score xs ys = Array.fold2 (fun sum x y -> sum + if x > y then 1 else 0) 0 xs ys
printfn "%d %d" (score a b) (score b a)
