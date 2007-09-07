/* missing functions for Itcl to avoid including of tclInt.h */

#ifndef _TCLINT
/* these functions exist but are NOT PUBLISHED */
EXTERN int Tcl_PushCallFrame (Tcl_Interp * interp,
                Tcl_CallFrame * framePtr,
	        Tcl_Namespace * nsPtr, int isProcCallFrame);
EXTERN void Tcl_PopCallFrame (Tcl_Interp * interp);
EXTERN void Tcl_GetVariableFullName (Tcl_Interp * interp,
                Tcl_Var variable, Tcl_Obj * objPtr);
EXTERN Tcl_Var Tcl_FindNamespaceVar (Tcl_Interp * interp,
                CONST char * name, Tcl_Namespace * contextNsPtr, int flags);
/* end of functions that exist but are NOT PUBLISHED */
#endif


/* here come the definitions for code which should be migrated to Tcl core */
/* these functions DO NOT exist and are not published */
typedef struct Tcl_Proc_ *Tcl_Proc;

typedef struct Tcl_CallFrameInfo {
    Tcl_Namespace *nsPtr;
    int flags;
    int objc;
    Tcl_Obj *CONST *objv;
    Tcl_CallFrame CONST *callerPtr;
    Tcl_CallFrame CONST *callerVarPtr;
    int level;
    Tcl_Proc procPtr;
    ClientData clientData;
#ifdef ARNULF_FOR_ITCL_CODE
    Tcl_Resolve *resolvePtr;
#endif
} Tcl_CallFrameInfo;

#define Tcl_GetOriginalCommand _Tcl_GetOriginalCommand
#define Tcl_GetNamespaceCommandTable _Tcl_GetNamespaceCommandTable
#define Tcl_GetNamespaceVariableTable _Tcl_GetNamespaceVariableTable
#define Tcl_GetNamespaceChildTable _Tcl_GetNamespaceChildTable
#define Tcl_InitRewriteEnsemble _Tcl_InitRewriteEnsemble
#define Tcl_ResetRewriteEnsemble _Tcl_ResetRewriteEnsemble
#define Tcl_CreateProc _Tcl_CreateProc
#define Tcl_ProcDeleteProc _Tcl_ProcDeleteProc
#define Tcl_GetObjInterpProc _Tcl_GetObjInterpProc
#define Tcl_SetProcCmd _Tcl_SetProcCmd
#define Tcl_SetNamespaceResolver _Tcl_SetNamespaceResolver
#define Tcl_InvokeNamespaceProc _Tcl_InvokeNamespaceProc


EXTERN Tcl_Command _Tcl_GetOriginalCommand(Tcl_Command command);
EXTERN Tcl_HashTable *_Tcl_GetNamespaceChildTable(Tcl_Namespace *nsPtr);

EXTERN Tcl_HashTable *_Tcl_GetNamespaceCommandTable(Tcl_Namespace *nsPtr);
EXTERN int _Tcl_InitRewriteEnsemble(Tcl_Interp *interp, int numRemoved,
	int numInserted, int objc, Tcl_Obj *const *objv);
EXTERN void _Tcl_ResetRewriteEnsemble(Tcl_Interp *interp,
        int isRootEnsemble);
EXTERN int _Tcl_CreateProc(Tcl_Interp *interp, Tcl_Namespace *nsPtr,
	CONST char *procName, Tcl_Obj *argsPtr, Tcl_Obj *bodyPtr,
        Tcl_Proc *procPtrPtr);
EXTERN void _Tcl_ProcDeleteProc(ClientData clientData);
EXTERN void *_Tcl_GetObjInterpProc(void);
EXTERN int _Tcl_SetNamespaceResolver(Tcl_Namespace *nsPtr,
        Tcl_Resolve *resolvePtr);
EXTERN int _Tcl_InvokeNamespaceProc(Tcl_Interp *interp, Tcl_Proc proc,
        Tcl_Namespace *nsPtr, Tcl_Obj *namePtr, int objc, Tcl_Obj *const *objv);
EXTERN int Tcl_NewNamespaceVars(Tcl_Interp *interp, Tcl_Namespace *nsPtr,
        int argc, char *argv[]);
EXTERN Tcl_Var Tcl_NewNamespaceVar(Tcl_Interp *interp, Tcl_Namespace *nsPtr,
	const char *varName);
EXTERN int Itcl_IsCallFrameArgument(Tcl_Interp *interp, const char *name);


/* end migration code */

