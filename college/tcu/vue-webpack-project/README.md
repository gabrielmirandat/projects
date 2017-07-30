# vue-webpack-project

> A Vue.js project

## Build Setup

``` bash
# install dependencies
npm install

# serve with hot reload at localhost:8080
npm run dev

# build for production with minification
npm run build

# build for production and view the bundle analyzer report
npm run build --report

# run unit tests
npm run unit

# run e2e tests
npm run e2e

# run all tests
npm test

## added for karma configuration
### from http://karma-runner.github.io/0.13/config/browsers.html
npm install karma-chrome-launcher --save-dev

module.exports = function(config) {
  config.set({
    browsers : ['Chrome', ...]
  });
};

### from http://www.damirscorner.com/blog/posts/20161018-DebuggingKarmaTestsInABrowser.html and Karma docs
{
  "scripts": {
    "unit-watch": "cross-env BABEL_ENV=test karma start test/unit/karma.conf.js --single-run=false --auto-watch"
  }
}

npm run unit-watch

### 


```
For detailed explanation on how things work, checkout the [guide](http://vuejs-templates.github.io/webpack/) and [docs for vue-loader](http://vuejs.github.io/vue-loader).
