# Scaling long range interactions in GROMACS' Replica-Exchange

The GROMACS addon enables custom definition, and calculation of scaled long range (LR) interactions (intra- and inter-molecular, charge, and Van der Waals). A deck specification in the topology separately for Van der Waals, and for charge is all that is needed to specify the strength of coupling.

Relevant section of the topology file:
>[molecules]
>; Compound #mols
>Protein_X 1
>POPC 128
>SOL 9955
>NA 28
>CL 32

>`[ scale_vdw ]`
>`; Specify this section after 'molecules' section`
>`1.0`
>`0.8 1.0`
>`1.0 1.0 0.2`
>`1.0 1.0 1.0 0.0`
>`1.0 1.0 1.0 1.0 1.0`

>`[ scale_q ]`
>`; Lower triangular matrix includes the diagonal`
>`1.0`
>`0.8 0.2`
>`0.2 0.0 1.0`
>`1.0 1.0 1.0 1.0`
>`1.0 1.0 1.0 1.0 1.0`
