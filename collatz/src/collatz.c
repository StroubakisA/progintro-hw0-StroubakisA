#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
	//  O ariumos o opoios prokuptei se kaue epanalhpsh toy typoy collatz
	register unsigned long long N;
	
	// Ariumodeikths
	register int unsigned i;
	
	// metrhths
	register unsigned int count;
	
	// Dynamikos piankas ston opoio ua apouhkeuontai ta mhkh poy exoyn upologistei 
	register unsigned short * lengths;
	
	// bohuitikos deikths
	register unsigned short * length_ptr;
		
		
	register unsigned int end; // oi duo ariumoi poy dinei o xrhsths.
	unsigned int start;
	register unsigned int max; // To zhtoumeno megisto
	
	// bhma elegxoy megistoy
	register int step;
	
	//Elegxos plhuoys orismatwn	
	if(argc!=3){
		
		printf("Number of arguments error\n");
		return 0;	
		
	}
	
	// Metatroph se akeraioys
	start=atoi(argv[1]);
	end=atoi(argv[2]);
	
	// An o telikos ariumos einai perittos,ton ayjanoyme kata 1
	// (To apotelesma den allazei kai boleyei stis prajeis)
	if(end&1)
		end++;

	// Desmeuetai pinakas gia ta mhkh
	lengths = malloc((end+1)*sizeof(short));
	
	// gia i=1 to mhkos einai 1 kai gia i=2 to mhkos einai 2
	lengths[1]=1;
	lengths[2]=2;
	
	//Arxikopoihsh toy i gia th epanalhptikh efarmogh
	i=3;
	
	// H epanalhptikh efarmogh ua ftasei mexri peritto
	end++;	
	
	while(i!=end){
	// Sthn arxh toy while,to i einai peritto.
	
		// To n arxikopoieitai se ayto...
		N=i;
		
		// ...kai ο metrhths arxikopoieitai sto 0.
		count=0;
		do{
			
			// O metrhths aujanetai kata 1
			count++;	
			
			// An to n einai peritto,tote tiuetai  Ν=3*Ν+1 kai sunexizei to loop
			if(N&1){
				N = (N << 1)+N+1;
		
				continue;				
			}				
			
			// Diaforetika tiuetai Ν=Ν/2
			N=N>>1;
						
		// An to N ginei mikrotero tou i den xreiazetai na proxvrhsoun oi upologismoi
		// giati to mhkos ths "ulopoihshs diadromhs"einai gnwsto.		
		}while(N>i);
		
		// Prostiuetai to upoloipo mhkos ths diadromhs kai prokuptei to mhkos gia to i
		// Parallhla to i aujanetai kata 1.
		lengths[i++]=count+lengths[N];

		// To i twra einai artio 
		// H diadromh tou exei mhkos kata 1 megalytero apo to mhkos ths diadromhs toy i/2
		lengths[i]=lengths[(i)>>1]+1;
		
		// To i aujanetai kata 1 kai ginetai pali peritto.
		i++;

	}
	// Apokatstash toy end
	end--;
	
	// To megisto mhkos ua anhkei se ariumo sigoura megaluyero toy end/3
	i=end/3;
	
	// An omws to start einai akoma megalutero tote h ekkinhsh entopismoy toy megisoty 
	// mhkous ua ginei apo ayto.  
	if(start>i)
		i=start;
	
	// An to i einai artio aujanetai kata 1.H ekkinhsh entopismou sumferei na ginei apo 
	// peritto.
	if(!(i&1))
		i++;
	
	length_ptr=lengths+i;	
	lengths+=end+1;	
	max=0;
	
	// Gia megalo end elegxontai mono oi perittoi 
	if(end>10000)
		step=2;
	else
		step=1;

	while(length_ptr!=lengths){
		
		if(*length_ptr>max)
			max=*length_ptr;
		
		length_ptr+=step;
			
	}
	
	// Tupwnetai to megisto mhkos
	printf("%d\n",max);
	
	// Apeleuuerwsh mnhmhs
	lengths-=end+1;
	free(lengths);
	
	return 0;
	
}
