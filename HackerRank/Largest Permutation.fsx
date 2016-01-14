open System

match Console.ReadLine().Trim().Split(' ') |> Array.map int with
| [|n; k|] ->
  let a = Console.ReadLine().Trim().Split(' ') |> Array.map int
  let indices = Array.zeroCreate n
  for i = 0 to n - 1 do
    indices.[a.[i] - 1] <- i
  let rec sortBySwapping number remaining =
    if remaining > 0 && number > 1 then
      let desiredIndex = n - number
      if indices.[number - 1] <> desiredIndex then
        let old = a.[desiredIndex]
        a.[desiredIndex] <- number
        a.[indices.[number - 1]] <- old
        indices.[old - 1] <- indices.[number - 1]
        indices.[number - 1] <- desiredIndex
        sortBySwapping (number - 1) (remaining - 1)
      else
        sortBySwapping (number - 1) remaining
  sortBySwapping n k
  printfn "%s" (String.Join(" ", a |> Array.map string))
| _ ->
  failwith "Invalid input"
