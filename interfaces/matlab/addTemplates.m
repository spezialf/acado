% Licence:
%    This file is part of ACADO Toolkit  - (http://www.acadotoolkit.org/)
%
%    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
%    Copyright (C) 2008-2009 by Boris Houska and Hans Joachim Ferreau, K.U.Leuven.
%    Developed within the Optimization in Engineering Center (OPTEC) under
%    supervision of Moritz Diehl. All rights reserved.
%
%    ACADO Toolkit is free software; you can redistribute it and/or
%    modify it under the terms of the GNU Lesser General Public
%    License as published by the Free Software Foundation; either
%    version 3 of the License, or (at your option) any later version.
%
%    ACADO Toolkit is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
%    Lesser General Public License for more details.
%
%    You should have received a copy of the GNU Lesser General Public
%    License along with ACADO Toolkit; if not, write to the Free Software
%    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
%
%    Author: Rien Quirynen
%    Date: 2012
% 

templateFiles = {'integrator_mex.c.in', 'rhs_mex.c.in', 'mpc_mex.c.in', 'mhe_mex.c.in'};
templates = {'INTEGRATOR_MEX_TEMPLATE', 'RHS_MEX_TEMPLATE', 'MPC_MEX_TEMPLATE', 'MHE_MEX_TEMPLATE'};

fid = fopen('./bin/include/acado/code_generation/templates/templates.hpp', 'w+');

fprintf(fid, '%s \n', ' #ifndef ACADO_TOOLKIT_TEMPLATES_HPP');
fprintf(fid, '%s \n\n', ' #define ACADO_TOOLKIT_TEMPLATES_HPP');

for i = 1:length(templates)
    tempString = sprintf(' #define %s "%s/../../src/code_generation/templates/%s" \n\n', char(templates(i)), pwd, char(templateFiles(i)));
    if ispc
        tempString = regexprep( tempString, '\', '/' );
    end
    fprintf(fid, '%s', tempString);
end

fprintf(fid, '%s \n', ' #endif // ACADO_TOOLKIT_TEMPLATES_HPP');

fclose(fid);

