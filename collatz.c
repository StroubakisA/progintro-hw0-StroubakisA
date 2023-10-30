/* Ακόμα καποιες βελτιώσεις είναι να ο πίνακας Lengths να είναι short (πιο μικρός) 
και να ζητήσουμε και άλλους registers */

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[]){
	
	register long N;

	register int i;
	register int count;
	
	// Δυναμικός πίνακας στον οποίο θα αποθηκεύονται τα μήκη που έχουν υπολογιστεί
	register short * lengths;
	
	register int end,max; // Οι δυο αριθμοί που δίνει ο χρήστης.
	int start;
	
	
	if(argc!=3){
		
		printf("Number of arguments error!\n");
		return 0;	
		
	}
	
	start=atoi(argv[1]);
	end=atoi(argv[2]);
	
	// Δεσμεύουμε χώρο για τον πίνακα (μία θέση παραπάνω από το emd. Π.χ για end=1000 δεσμεύουμε 1001 θέσεις)
	lengths = malloc((end+1)*sizeof(int));
	
	if(lengths==NULL){
		printf("No mem!\n");
		return 0;
	}
	
	// Μηδενίζουμε όλες τις θέσεις του πίνακα 
	for(i=0;i<=end;i++)
		lengths[i]=0;
		
	if(start>end)
		return 0;
	max=0;
	
	for(i=start;i<=end;i++){

		N=i;
		count=1;
		while(N!=1){
			
			// Συμπλήρωση κώδικα: Στην αρχή κάθε γύρου, ελέγχεται αν έχει υπολογιστεί ήδη το μήκος Ν
			if(N<=end){
				if(lengths[N]!=0){
					// Aν έχει υπολογιστεί ήδη, τότε απλά προστίθεται στο τρέχον, αφαιρείται το 1 και το Loop σπάει 
					count+=lengths[N]-1;
					break;		
					
				}
			}
						
			if(N%2==1)
				N=N+N+N+1;
			else
				N=N>>1;
			count=count+1;
			
		}
		
		// Κάθε φορά που υπολογίζεται ένα νέο μήκος ενημερώνεται ο πίνακας 
		lengths[i]=count;
		
		if(count>max)
			max=count;
		
	}
	printf("%d\n",max);
	return 0;
	
}
