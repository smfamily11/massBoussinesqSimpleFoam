{
    int iter = 0;
    scalar residual = 1;
    scalar meanResidual = 1;

    const dictionary& meltDict = mesh.solutionDict().subDict("subdict");
    int minTCorr(readLabel(meltDict.lookup("minTempCorr")));
    int maxTCorr(readLabel(meltDict.lookup("maxTempCorr")));
    scalar alphaTol(readScalar(meltDict.lookup("alphaTol")));
    scalar alphaRel(readScalar(meltDict.lookup("alphaRelax")));

    const dimensionedScalar dumt("1", dimensionSet(0,0,1,0,0,0,0), 1);

    for (iter = 0; (iter < minTCorr || residual > alphaTol) && iter < maxTCorr; iter++)
    {
        alpha1.storePrevIter();

	fvScalarMatrix rhofEqn
	(
	    fvm::ddt(rhof)

//	  + fvc::ddt(alpha1)
//	  + fvc::div(phi, alpha1)
//	  - fvc::laplacian(Dt, alpha1)
	 ==
	    Lv*(Y - YSat)/dumt
	);

	rhofEqn.solve();

	rhof.max(0);

    }

}
