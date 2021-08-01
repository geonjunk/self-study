# 리액트 공부
## 리액트 동작원리
* 프로젝트 src 폴더에 있는 자바스크립트 코드를 리액트가 받아와서 해석하고 해석한 결과물을 html(index.html)에 끼워넣음
* ReactDOM.render(컴포넌트, 그릴 곳) : 해당 컴포넌트를 그릴 곳에 그림
    * ex) ReactDOM.render(<App />,document.getElementById('root')); -> app 컴포넌트를, 아이디가 root인 element에 그린다
* 리액트는 일부 HTML만 그린 후 엘리멘트를 추가하거나 제거하는 방식으로 화면을 그림 -> 화면에 표시될 모든 HTML을 처음부터 그리지 않기 때문에 빠름

## 리액트 기초 개념 알아보기
### 리액트 앱 실행 복습
* App()함수의 리턴값이 많아지면 소괄호로 감싸줘야함
```
function App() {
  return (<div>
    <h1>Hello REACT!</h1>
    </div>);
}
```
### 컴포넌트(Component)
* App.js 에서 App()함수가 HTML을 반환함 -> App()함수를 App 컴포넌트라 함
```
function App() {// App컴포넌트 정의
  return (<div>
    <h1>Hello REACT!</h1>
    </div>);//App 컴포넌트가 HTML 반환함
}
```
* 컴포넌트 import 해서 사용하는 법
    ```
    import React from 'react';
    import ReactDOM from 'react-dom';
    import App from './App';// App 컴포넌트 임포트


    ReactDOM.render(<App />,document.getElementById('root'));//임포트한 App컴포넌트 사용
    ```
    * 리액트는 HTML 태그같은 표시를 컴포넌트로 인식함(ex)<App/>) 
    * ReactDOM.render()함수의 첫번째 인자로 컴포넌트 전달하면 해당 컴포넌트가 리턴하는 값을 두번째 인자의 위치의 그려짐
* 리액트는 컴포넌트와 함께 동작하고 모두 컴포넌트로 구성됨

### JSX
* 컴포넌트는 JS와 HTML을 조합한 JSX라는 문법을 사용해서 생성
* 컴포넌트 만들기 ex) Potato 컴포넌트 생성하고 사용하기
    * Potato 컴포넌트 생성
    ```javascript:Potato.js
    import React from 'react'; // 이 코드를 입력해야 리액트가 JSX인식 가능

    function Potato(){//컴포넌트 이름은 대문자로 시작해야함!
        return <h3>I love Potato</h3>;// JSX 반환(아직 HTML만으로 구성됨)
    }

    export default Potato;//export하여 다른 파일에서 Potato 컴포넌트 사용 가능하게 함
    ```
    * Potato 컴포넌트 사용법
        * 잘못된 사용법
            * 리액트는 최종적으로 단 하나의 컴포넌트만 그릴 수 있음, 따라서 두 개 이상의 컴포넌트 그리려 하면 에러 발생
            ```
            import React from 'react';
            import ReactDOM from 'react-dom';
            import App from './App';


            ReactDOM.render(<App /><Potato />,document.getElementById('root'));
            ```
            * 따라서 Potato컴포넌트를 App컴포넌트 안에 넣어서 사용해야 함
        * 올바른 사용법
            * App 컴포넌트에 Potato 컴포넌트를 임포트
            * App 컴포넌트에 <Potato />를 추가해 리턴
            ```
            import React from 'react';
            import Potato from './Potato';

            function App() {
            return (<div>
                <h1>Hello REACT!</h1>
                <Potato/>
                </div>);
            }

            export default App;
            ```
    * App 컴포넌트 안에 Potato 컴포넌트 만들기
        * App.js 파일에 Potato() 함수 만들면 됨
        * 파일 여러개 사용하기 불편하면 사용하면 됨
        ```
        import React from 'react';


        function Potato(){
        return <h3>I love Potato</h3>;
        }

        function App() {
        return (<div>
            <h1>Hello REACT!</h1>
            <Potato/>
            </div>);
        }

        export default App;

        ```
### props
* 컴포넌트에서 컴포넌트로 전달하는 데이터
* props를 사용하여 컴포넌트 효율적으로 재사용 가능
* 컴포넌트에 props 전달하면 props에 있는 데이터가 하나의 객체로 변환되어 컴포넌트의 인자로 전달되고 이걸 받아서 컴포넌트(함수)에서 사용 가능해짐
* ex) Food 컴포넌트
    * 컴포넌트에 props 전달하기
        * 문자열은 ""(또는 '')로 감싸며, 문자열 아닌값은 {}(중괄호)로 감싼다 
        ```
        <Food fav="kimchi" something={true} papa={['hello',1,2,3]}/> 
        ```
    * props 사용하기
        * Food 컴포넌트의 인자로 props 받아서 사용
            ```
            function Food(props){
            return <h3>I love {props.fav}</h3>;
            }
            ```
        * 구조 분해 할당으로도 사용가능
            ```
            function Food(props){
            const {fav}=props;
            return <h3>I love {fav}</h3>;
            }

            function Food({fav}){
            return <h3>I love {fav}</h3>;
            }
            ```
    * 여러 개의 컴포넌트에 props사용하기
        * 각 컴포넌트마다 다른 fav값을 출력하여 컴포넌트 재사용
        ```
        function App() {
            return (<div>
                <h1>Hello REACT!</h1>
                <Food fav="kimchi"/>
                <Food fav="ramen"/>
                <Food fav="pizza"/>
                <Food fav="orange"/>
                <Food fav="salad"/>   
                </div>);
        }

        ```
### 비슷한 컴포넌트 여러 개 만들기와 map함수
* 중복된 컴포넌트를 직접 여러 번 입력하는건 효율적이지 않은 방법임
    * 100개 이상, 1000개 이상 입력하는 경우도 있음
    * 중복된 데이터의 개수를 모르는 경우 (서버에서 그때그때 넘어오는 경우 등)에도 문제가 됨
    ```
          function App() {
            return (<div>
                <h1>Hello REACT!</h1>
                <Food fav="kimchi"/>
                <Food fav="ramen"/>
                <Food fav="pizza"/>
                <Food fav="orange"/>
                <Food fav="salad"/>   
                </div>);
        }
    ```
* map() 함수
    * 배열의 모든 원소마다 특정 작업을 하는 함수를 적용하고, 그 함수가 반환한 결과를 모아 배열로 반환해주는 함수
    * 첫번쨰 인자로 특정 작업을 하는 함수 전달
    * 사용 예) 각 값의 * 추가
        ```
        const friends=["dal","jun","lynn"];
        friends.map(current=>{//current 배열의 각 원소
            console.log(current);
            return current+"*"; // 최종 반환값
        })
        ```
* map함수를 이용해 중복 컴포넌트 출력하기
    * 중괄호로 함수 감싸서 JSX 부분에 넣어주기
    * 컴포넌트에서 return 시 div로 감싸서 리턴해주기
    * img 태그 리턴시 alt 속성도 넣어주기
    ```
        function Food({name,picture}){
        return (
        <div>
            <h2>I like {name}</h2>
            <img src={picture} alt={name} />
        </div>
        );
        }
    function App() {
    return (<div>
        {foodILike.map(dish=>(<Food name={dish.name}/>))};  
        </div>);
    }
    ```
* map() 함수의 인자로 함수 전달하기
    ```
    function renderFood(dish){
        return <Food name={dish.name} picture={dish.image}/>;
    }
    function App() {
    return (
        <div>
        {foodILike.map(renderFood)};  
        </div>
        );
    }

    ```
    * App.js에 함수가 많아지면 관리 어려워질 수 있기때문에 지양함
* Warning: Each child in a list should have a unique "key" prop.경고 뜻
    * 리스트의 각 원소는 유일한 key prop를 가져야 한다는 뜻
    * 리액트의 원소들은 유일해야 하는데 리액트 원소가 리스트에 포함되면서 key값이 없기 때문에 유일성이 없어짐
        * 각 원소들(컴포넌트들)이 서로 다르다는 것 알 방법이 없음
    * 해결위해 배열원소에 id란 값(즉, key props)을 추가한다
    * key props를 전달해서 해결
        ```
         {foodILike.map(dish=>(<Food key={dish.id} name={dish.name} picture={dish.image}/>))};  
        ```

### prop-types
* 개발자가 정의한 props의 값이 컴포넌트에 제대로 전달되지 않은 경우가 있기 때문에 props를 검사하는 방법이 필요함
* prop-types 
    * props의 자료형을 검사하는 도구
    * npm을 통해 설치
    * 원하는 컴포넌트의 propTypes를 정의해 사용
        ```
        Food.propTypes={
            name : PropTypes.string.isRequired, //string 타입을 요구함
            picture : PropTypes.string.isRequired,
            rating : PropTypes.number.isRequired,
        };
        ```
        * isRequired를 빼면 필수는 아니지만 있으면 해당 타입이긴 해야 함

## state와 클래스형 컴포넌트
### state
* 동적 데이터(변경될 가능성이 있는 데이터)를 다룰 때 사용
    * ex) 객체의 경우 객체의 구성 요소 중 일부가 있다가 없을 수도 있고, 구성 요소가 하나였다가 둘이 될 수도 있고
    * props는 그러한 데이터를 다루지 못함
* 클래스형 컴포넌트와 함께 사용할 수 있는 개념
### 클래스형 컴포넌트
* 클래스형 컴포넌트의 구성
    ```
    class App extends React.Component{//App클래스가 react.component 클래스 상속받음
    render(){
        return <h1>I'm a class component</h1>;
    }
    }
    ```
    * React.Component 클래스를 상속받아야함
    * JSX를 리턴하기 위해 render함수를 사용
    * 리액트는 클래스형 컴포넌트의 render함수를 자동으로 실행함 -> 즉, 직접 실행 안해도 됨
* state 정의 및 사용
    * state는 객체이므로 state={};형식으로 정의
    * 리액트는 state를 직접 변경하는 코드 허용하지 않음
        * 원래 리액트는 state가 변경되면 render함수를 다시 실행하여 변경된 state를 화면에 출력하는데 직접 state를 변경한 경우에는 render를 다시 실행하지 않음
    * state 값 변경하려면 setState()함수를 이용해 변경해야함
        ```
        class App extends React.Component{//App클래스가 react.component 클래스 상속받음
            state={
                count:0,
            };
            add=()=>{
                console.log(`add`);
                this.setState({count:1});
            };
            minus=()=>{
                console.log(`minus`);
                this.setState({count:-1});
            }
            render(){
                return (
                <div>
                <h1>The number is : {this.state.count}</h1>
                <button onClick={this.add}>Add</button>
                <button onClick={this.minus}>Minus</button>
                </div>
                );
            }
        }

        
        ```
        * 필요한 부분만 빠르게 바뀌므로 리액트는 화면 구성이 빠르다는 장점이 보임
        * 예) 1씩증가 감소 시키기
            ```
            class App extends React.Component{//App클래스가 react.component 클래스 상속받음
                state={
                    count:0,
                };
                add=()=>{
                    console.log(`add`);
                    this.setState({count : this.state.count+1});
                };
                minus=()=>{
                    console.log(`minus`);
                    this.setState({count:this.state.count-1});
                }
                render(){
                    return (
                    <div>
                    <h1>The number is : {this.state.count}</h1>
                    <button onClick={this.add}>Add</button>
                    <button onClick={this.minus}>Minus</button>
                    </div>
                    );
                }
            }
            ```
    * {count:this.state.count-1}와 같이 코드를 작성하여 state를 업데이트 하는 방법은 성능 문제 생길 수 있음
    * 그 대신 setState()함수의 인자로 함수를 전달하여 성능 문제 해결
        ```
        add=()=>{
            console.log(`add`);
            this.setState(current=>({
            count : current.count+1,
            })
            );
        };
        minus=()=>{
            console.log(`minus`);
            this.setState(current=>({
            count : current.count-1,
            })
            );
        }
        ```
        * current에는 현재 state가 넘어옴
        * setState함수는 state의 바뀐 데이터만 업데이트 함
        * 수정된 객체를 반환하게 함수 구성

### 클래스형 컴포넌트의 생명주기
```
class App extends React.Component{//App클래스가 react.component 클래스 상속받음
  constructor(props){
    super(props);
    console.log(`hello`);
  }
  state={
    count:0,
  };
  add=()=>{
    console.log(`add`);
    this.setState(current=>({
      count : current.count+1,
    })
    );
  };
  minus=()=>{
    console.log(`minus`);
    this.setState(current=>({
      count : current.count-1,
    })
    );
  }
  render(){
    console.log(`rendering`);
    return (
    <div>
      <h1>The number is : {this.state.count}</h1>
      <button onClick={this.add}>Add</button>
      <button onClick={this.minus}>Minus</button>
    </div>
    );
  }
  componentDidMount(){
    console.log(`component rendered`);
  }
  componentDidUpdate(){
    console.log(`component updated`);
  }
  componentWillUnmount(){
    console.log(`GoodBye`);
  }
}
```
* constructor() 함수
    * 클래스형 컴포넌트가 생성될 때 호출
    * super() : super 키워드는 부모 클래스로부터 상속받은 필드나 메소드를 자식 클래스에서 참조하는 데 사용하는 참조 변수
    * render보다 먼저 실행됨
* componentDidMount()
    * render()함수가 실행된 다음 실행되는 함수 
    * 즉, app컴포넌트가 다 그려지면 실행되는 함수
    * 리액트가 Mount로 분류하는 생명주기 함수
* componentDidUpdate()
    * 화면이 업데이트되면(다시 그려지면)실행 됨
    * ex) setState()-> render()로 화면 다시 그림 -> componentDidUpdate() 실행
* componentWillUnmount()
    * 컴포넌트가 죽을 때(Unmount)와 관련된 함수
    * 컴포넌트가 화면에서 떠날 때 실행됨

### axios
* 데이터를 로딩하려면 원래는 js의 fetch()함수가 필요하지만 함수 대신 axios라는 도구를 사용해서도 가능함
* axios는 네트워크를 사용하므로 느리게 동작 -> JS에게 axios.get()을 포함하고 있는 함수의 실행이 끝날 때까지 기다려야한다고 말해야 함
    * async/await 이용
* axios를 이용해 영화 API 호출하기
```
  getMoives=async()=>{
    const movies=await axios.get(`https://yts-proxy.now.sh/list_movies.json`);
  }
  componentDidMount(){ 
   this.getMoives();
  }
```