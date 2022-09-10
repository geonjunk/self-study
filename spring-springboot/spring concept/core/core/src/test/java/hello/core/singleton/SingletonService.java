package hello.core.singleton;

public class SingletonService {
    //static 영역에 자기 자신을 내부에 하나만 갖게 함, 모든 객체가 하나의 멤버를 공유하여 어디서든 참조할 수 있는 장점
    private static final SingletonService instance = new SingletonService();

    public static SingletonService getInstance(){
        return instance;
    }

    //다른 곳에서 생성자 호출 못하도록 private 생성자 사용
    private SingletonService(){
        
    }
    
    public void logic(){
        System.out.println("싱글톤 객체 로직 호출");
    }
}
