open System

match Console.ReadLine().Split(' ') |> Array.map int with
| [|n; k|] ->
  let costs = Console.ReadLine().Split(' ') |> Array.map int |> Array.sort
  let rec buyFlowers acc iteration remaining =
    if remaining = 0 then
      acc
    else
      let buy = min remaining k
      buyFlowers
        (acc + iteration * Array.sum costs.[remaining - buy .. remaining - 1])
        (iteration + 1)
        (remaining - buy)
  printfn "%d" (buyFlowers 0 1 n)
| _ ->
  failwith "Invalid input"
