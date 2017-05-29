let divRem x y = (x / y, x % y)
let moves x =
  let m5, x = divRem x 5
  let m2, m1 = divRem x 2
  m5 + m2 + m1

let t = stdin.ReadLine() |> int
for _ in 1 .. t do
  let n = stdin.ReadLine() |> int
  let xs = stdin.ReadLine().Split(' ') |> Array.map int
  let a = xs |> Array.min
  let xs = xs |> Array.map (fun x -> x - a)
  {0 .. 4}
  |> Seq.map (fun b -> xs |> Array.fold (fun acc x -> acc + moves (x + b)) 0)
  |> Seq.min
  |> printfn "%d"
