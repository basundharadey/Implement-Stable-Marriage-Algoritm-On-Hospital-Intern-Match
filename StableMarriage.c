
#include <stdio.h>
 
int flag = 0;
enum {
	dummyPartner = -1,
	michael, adams, cynthia, simons, gillchrist, fred, britney, mathew, taylor, smith,
	cardiology, neurology, endocrinology, oncology, anesthesiology, cardiothoractic_surgery, pediatric_surgery, surgical_surgery, pathology, radiology,
};
const char *nameOfPartners[] = {
	"Michael", "Adams", "Cynthia",  "Simons", "Gillchrist",  "Fred", "Britney", "Mathew",  "Taylor", "Smith",
	"Cardiology", "Neurology", "Endocrinology", "Oncology", "Anesthesiology", "Cardiothoractic_surgery",  "Pediatric_surgery", "Surgical_surgery", "Pathology", "Radiology"
};
int preferenceForMedicalInterns[radiology + 1][smith + 1] = {
	{ cardiology, anesthesiology, endocrinology, pathology, radiology, oncology, cardiothoractic_surgery, neurology, surgical_surgery, pediatric_surgery },
	{ endocrinology, surgical_surgery, cardiology, oncology, anesthesiology, cardiothoractic_surgery, neurology, radiology, pathology, pediatric_surgery },
	{ surgical_surgery, anesthesiology, cardiology, oncology, neurology, cardiothoractic_surgery, pathology, pediatric_surgery, endocrinology, radiology },
	{ pathology, cardiothoractic_surgery, oncology, pediatric_surgery, surgical_surgery, anesthesiology, radiology, neurology, endocrinology, cardiology },
	{ radiology, oncology, neurology, endocrinology, cardiothoractic_surgery, anesthesiology, cardiology, pathology, surgical_surgery, pediatric_surgery },
	{ neurology, cardiology, oncology, pediatric_surgery, anesthesiology, pathology, endocrinology, radiology, surgical_surgery, cardiothoractic_surgery },
	{ pediatric_surgery, anesthesiology, pathology, neurology, endocrinology, cardiology, oncology, surgical_surgery, radiology, cardiothoractic_surgery },
	{ cardiology, anesthesiology, surgical_surgery, cardiothoractic_surgery, pathology, endocrinology, radiology, neurology, pediatric_surgery, oncology },
	{ surgical_surgery, endocrinology, oncology, pediatric_surgery, neurology, cardiology, cardiothoractic_surgery, pathology, radiology, anesthesiology },
	{ cardiology, cardiothoractic_surgery, radiology, pediatric_surgery, anesthesiology, neurology, oncology, endocrinology, pathology, surgical_surgery },
 
	{ adams, fred, smith, britney, taylor, michael, simons, gillchrist, cynthia, mathew   },
	{ adams, michael, cynthia, fred, britney, simons, taylor, gillchrist, smith, mathew   },
	{ fred, adams, gillchrist, britney, mathew, cynthia, taylor, michael, simons, smith   },
	{ fred, smith, cynthia, michael, taylor, mathew, britney, simons, adams, gillchrist   },
	{ smith, mathew, fred, simons, michael, britney, cynthia, gillchrist, taylor, adams   },
	{ adams, michael, gillchrist, taylor, smith, simons, fred, britney, cynthia, mathew   },
	{ smith, britney, mathew, fred, adams, michael, cynthia, gillchrist, simons, taylor   },
	{ britney, smith, adams, michael, taylor, simons, mathew, gillchrist, cynthia, fred   },
	{ taylor, cynthia, mathew, britney, fred, adams, michael, gillchrist, smith, simons   },
	{ gillchrist, mathew, britney, michael, adams, smith, cynthia, taylor, fred, simons   },
};
int pairsForMedicalInterns[radiology + 1], proposedForTheirChoice[radiology + 1];
 
void EngageThePairs(int specialization, int medicalIntern)
{
	pairsForMedicalInterns[medicalIntern] = specialization;
	pairsForMedicalInterns[specialization] = medicalIntern;
		printf("\n%5s Pairs with %5s\n", nameOfPartners[medicalIntern], nameOfPartners[specialization]);	

	if (flag)
	{
	printf("%5s Pairs with %5s\n", nameOfPartners[medicalIntern], nameOfPartners[specialization]);	
	} 
}
 
void dumpThePairs(int medicalInterns, int specialization)
{
	pairsForMedicalInterns[specialization] = pairsForMedicalInterns[medicalInterns] = dummyPartner;
		printf("%5s removes %5s from pair\n", nameOfPartners[medicalInterns], nameOfPartners[specialization]);	

	if (flag) 
	{
	printf("%5s removes %5s from pair\n", nameOfPartners[medicalInterns], nameOfPartners[specialization]);	
	}
}
 
int rankThisSpecialisation(int this, int that)
{
	int i;
	for (i = michael; i <= smith && preferenceForMedicalInterns[this][i] != that; i++);
	return i;
}
 
void MedicalInternsProposeTheirChoice(int specialization, int medicalIntern)
{
	int choiceForSpecialisation = pairsForMedicalInterns[medicalIntern];
	if (flag) 
	
	{
	printf("%5s pairs with and makes offer to %5s\n", nameOfPartners[specialization], nameOfPartners[medicalIntern]);	
	}
 
	if (choiceForSpecialisation == dummyPartner) 
	{
		EngageThePairs(specialization, medicalIntern);
	} 
	else if (rankThisSpecialisation(medicalIntern, specialization) < rankThisSpecialisation(medicalIntern, choiceForSpecialisation)) 
	{
		printf("\n Unstable Pairing\n");
		dumpThePairs(medicalIntern, choiceForSpecialisation);
		printf("\n Pairs with next member of their choice\n");
		EngageThePairs(specialization, medicalIntern);
	}
}
 
int rearrangeMedicalInterns(int specialization1, int medicalIntern)
{
	if (rankThisSpecialisation(specialization1, medicalIntern) < rankThisSpecialisation(specialization1, pairsForMedicalInterns[specialization1]) &&
			rankThisSpecialisation(medicalIntern, specialization1) < rankThisSpecialisation(medicalIntern, pairsForMedicalInterns[medicalIntern])) 
			{
				printf( " \n   %5s (with/ %5s) and %5s (with/ %5s) prefers"	
						" over current preference.\n",
				nameOfPartners[specialization1], nameOfPartners[pairsForMedicalInterns[specialization1]], nameOfPartners[medicalIntern], nameOfPartners[pairsForMedicalInterns[medicalIntern]]
		);
		return 1;
	}
	return 0;
}
 
int SelectPreferredSpecialisation(int specialization1, int specialization2)
{	
	return rearrangeMedicalInterns(specialization1, pairsForMedicalInterns[specialization2]) + rearrangeMedicalInterns(specialization2, pairsForMedicalInterns[specialization1]);
}
 
int unstablePairing()
{
	int counter1, counter2, dirtyPairing = 0;
	for (counter1 = michael; counter1 < smith; counter1++) {
		for (counter2 = counter1 + 1; counter2 <= smith; counter2++)
			if (SelectPreferredSpecialisation(counter1, counter2)) 
			{
			dirtyPairing = 1;	
			}
	}
	return dirtyPairing;
}
 
int main()
{
	int counter, notPaired;	
	for (counter = michael; counter <= radiology; counter++)
	{
		pairsForMedicalInterns[counter] = proposedForTheirChoice[counter] = dummyPartner;
	}	
 
	do {
		notPaired = 0;
		for (counter = michael; counter <= smith; counter++) 
		{
			if (pairsForMedicalInterns[counter] != dummyPartner) 
			{
				continue;
			}
			notPaired = 1;
			MedicalInternsProposeTheirChoice(counter, preferenceForMedicalInterns[counter][++proposedForTheirChoice[counter]]);
		}
	} while (notPaired);
 	printf("\n Resultant Pairing of the Partners is as follows 	:\n");
	for (counter = michael; counter <= smith; counter++)
	{
		printf("  %10s - %s\n", nameOfPartners[counter],pairsForMedicalInterns[counter] == dummyPartner ? "dummyPartner" : nameOfPartners[pairsForMedicalInterns[counter]]);
	}
	

	return 0;
}
