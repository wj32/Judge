open System

match Console.ReadLine().Split(' ') |> Array.map int with
| [|a; b; n|] ->
  let rec loop t t_'1 n =
    if n = 2 then
      t
    else
      let t_1 = t * t + t_'1
      loop t_1 t (n - 1)
  printfn "%A" (loop (bigint b) (bigint a) n)
| _ ->
  failwith "Invalid input"
