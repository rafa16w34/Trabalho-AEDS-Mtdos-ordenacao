package sorts

func Shellsort(vet []int, n int){

		gap := 1
		j := 0
		aux := 0

		for gap<n {

			gap= 3 * gap+1
		}

		for gap>0 {

			gap= gap/3

			for i := gap; i<n; i++ {

				j= i
				aux= vet[i]
			
				for j>= gap && vet[j-gap]> aux {


					vet[j]= vet[j-gap]
					j= j-gap
				}
			
				vet[j]= aux
			
			
			
			}





		}
}