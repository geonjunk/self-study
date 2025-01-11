package hello.core.singleton;

public class SingletonService {

    private static SingletonService instance = new SingletonService();

    //다른 곳에서 생성자 호출 못하도록 private 생성자 사용
    private SingletonService() {

    }

    public static SingletonService getInstance() {
        return instance;
    }

    public void logic() {
        System.out.println("싱글톤 객체 로직 호출");
    }
}
