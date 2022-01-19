{
    alphat = turbulence->nut()/Prt;
    alphat.correctBoundaryConditions();

    volScalarField alphaEff("alphaEff", turbulence->nu()/Pr + alphat);

    fvScalarMatrix TEqn
    (
        fvm::div(phi, T)
      - fvm::laplacian(Dt2, T)
     ==
        radiation->ST(rhoCpRef, T)
      + fvOptions(T)
    );

    TEqn.relax();

    fvOptions.constrain(TEqn);

    TEqn.solve();

    radiation->correct();

    fvOptions.correct(T);

    rhok = 1.0 - beta*(T - TRef);

    const dimensionedScalar T30("30.11", dimensionSet(0,0,0,1,0,0,0), 30.11);
    const dimensionedScalar T273("273.15", dimensionSet(0,0,0,1,0,0,0), 273.15);
    const dimensionedScalar T1("1", dimensionSet(0,0,0,1,0,0,0), 1);
    const dimensionedScalar p610("610.94", dimensionSet(0,2,-2,0,0,0,0), 610.94);
    const dimensionedScalar pRef("101325", dimensionSet(0,2,-2,0,0,0,0), 101325);

    pSat = p610*exp(17.625*(T - T273)/max(T1, T - T30));

    YSat = 0.62198*(pSat/(pRef - pSat));
}
