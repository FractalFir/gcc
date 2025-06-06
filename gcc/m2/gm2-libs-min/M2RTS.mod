(* M2RTS.mod implement the smallest number of routines for linking.

Copyright (C) 2001-2025 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius.mulley@southwales.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  *)

IMPLEMENTATION MODULE M2RTS ;

IMPORT libc, SYSTEM ;
(* we reference these to ensure they are dragged in to the link *)


PROCEDURE ConstructModules (applicationmodule, libname: ADDRESS;
                            argc: INTEGER; argv, envp: ADDRESS) ;
BEGIN
END ConstructModules ;


PROCEDURE DeconstructModules (applicationmodule, libname: ADDRESS;
                              argc: INTEGER; argv, envp: ADDRESS) ;
BEGIN
END DeconstructModules ;


(*
   RegisterModule - adds module name to the list of outstanding
                    modules which need to have their dependencies
                    explored to determine initialization order.
*)

PROCEDURE RegisterModule (name, libname: ADDRESS;
                          init, fini:  ArgCVEnvP;
                          dependencies: PROC) ;
BEGIN
END RegisterModule ;


(* all these procedures do nothing except satisfy the linker.  *)

PROCEDURE ExecuteTerminationProcedures ;
BEGIN
END ExecuteTerminationProcedures ;


PROCEDURE ExecuteInitialProcedures ;
BEGIN
END ExecuteInitialProcedures ;


PROCEDURE HALT ;
BEGIN
   LOOP
   END
END HALT ;


PROCEDURE NoException (filename: ADDRESS;
                       line, column: CARDINAL; scope, message: ADDRESS) ;
BEGIN
END NoException ;


(*
   RequestDependant - used to specify that modulename is dependant upon
                      module dependantmodule.
*)

PROCEDURE RequestDependant (modulename, libname,
                            dependantmodule, dependantlibname: ADDRESS) ;
BEGIN
END RequestDependant ;


END M2RTS.
