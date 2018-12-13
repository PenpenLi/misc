//// [symbolDeclarationEmit14.ts]
class C {
    get [Symbol.toPrimitive]() { return ""; }
    get [Symbol.toStringTag]() { return ""; }
}

//// [symbolDeclarationEmit14.js]
class C {
    get [Symbol.toPrimitive]() { return ""; }
    get [Symbol.toStringTag]() { return ""; }
}


//// [symbolDeclarationEmit14.d.ts]
declare class C {
    [Symbol.toPrimitive]: string;
    [Symbol.toStringTag]: string;
}
