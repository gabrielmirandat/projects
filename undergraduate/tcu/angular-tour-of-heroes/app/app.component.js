"use strict";
var heroes_component_1 = require('./heroes.component');
var router_1 = require('@angular/router');
router_1.RouterModule.forRoot([
    {
        path: 'heroes',
        component: heroes_component_1.HeroesComponent
    }
]);
var AppComponent = (function () {
    function AppComponent() {
        this.title = 'Tour of Heroes';
    }
    return AppComponent;
}());
exports.AppComponent = AppComponent;
//# sourceMappingURL=app.component.js.map